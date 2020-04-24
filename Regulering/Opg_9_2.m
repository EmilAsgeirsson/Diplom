clc;
clear;
% Exercise 9.2
% Consider the mass-spring-damper system illustrated below with dynamics

m = 1;
k = 2;
c = 3;

A = [0 1;
     -k/m -c/m];
 
B = [0; 1/m];


C1 = [B A*B];


% 1. Transform the system to discrete time, with a sampling time of 0.05 s
% To discretize the state space model we're using built in matlab functions:
T = 0.05;
% C is set to be a 0 matrix. This C is not the controllability matrix.
sys = ss(A,B,C1,0);
d_sys = c2d(sys,T)

% 2. Calculate a control sequence u(0), u(1) for the discrete time system 
% such that x(2) = [2;1], when x(0) = [0;0].

% Create the controllability matrix
C = [d_sys.B d_sys.A*d_sys.B]
% checking rank of matrix
detC = det(C);
% The determinant is -1.0766e-04. Therefore the matrix has full rank and is
% controllable

% IMPORTANT NOTE: The dimensions of the matrix/vector changes in regards to
% which vector is multiplied first. Fx 2x2 times 2x1 returns a 2x1 vector.
% A 2x1 times 2x2 returns a 2x2 matrix.
x2 = [2; 1]
u = inv(C)*x2;

% The vector returned gives us u_n at the top down to u_0 at the buttom.
u0 = u(2)
u1 = u(1)

x21 = d_sys.A*d_sys.B*u0 + d_sys.B*u1

finalsys = ss(d_sys.A, d_sys.B, C, 0, T)
% 3. Verify the control by simulating the system in MATLAB
figure
%lsim(finalsys, u, T)
% step(finalsys)

% figure
% step(sys)


n = 16;
derr = @(x) exp(-2.0*pi*(pi/2)/x);
terr = @(x) exp(-2*x*n);
err = @(x) exp(-pi*sqrt(2*n));
figure
fplot(derr, [0 9])
hold on
fplot(terr, [0 9])
fplot(err, [0 9])
