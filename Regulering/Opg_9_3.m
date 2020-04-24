clc;
clear;
% Exercise 9.3
% Consider the following system

A = [1 1 0;
     0 1 1;
     0 0 1];
B = [0; 1; 1];

% Creating a controllability matrix
C = [B A*B A*A*B];
%Checking the contronability martix
detC = det(C)
% The determinant returns -1. Therefore the matrix is controllable.
% Calculating the T matrix using unknowns s and our A and B:
s3 = [0 0 1]*inv(C);
s2 = s3*A;
s1 = s2*A;

invT = [s1;s2;s3];

T = inv(invT);

% Here I calculate the Ac and Bc matrix using T.

Ac = invT*A*T
Bc = invT*B;
syms h

h1 = [h 0 0;
      0 h 0;
      0 0 h];
Ah = h-Ac;
% Next I find the lambda determinant
% det(lambda*I-A) = lambda^3 - 3*lambda^2 + 3*lambda - 1

% det(lambda-A) = [lambda-3 3         -1;
%                    -1         lambda   0;
%                    0          -1         lambda];
% P = (lambda-3)(lambda)(lambda) + (-1)(-1)(-1) - (3)*(-1)*(lambda);
% P = lambda^3 - 3lambda^2 + 3lambda - 1

% As can be seen above. You take the a variables from the Ac matrix and
% subtract from each lambda exponent. This is the same as calculating it.
% Simplifying:

% (h-1)(h-1)(h-1)
% h^3-h^2-h^2+h-h^2+h+h-1 = h^3-3h^2+3h-1

% This almost corresponds to the right value.
e = eig(Ah);

% 2. Based on the system description in controllable canonical form, 
% find a state feedback u = F x, such that the characteristic polynomial of
% the closed loop system is s^3 + 3s^2 + 6s + 4. Note that the feedback must
% be given in the original states.

%Fc is given by subtracting the desired closed loop from the open loop.
Fc = [3-3 -3-6 1-4]
F = Fc*invT


















