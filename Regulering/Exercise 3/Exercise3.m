% syms b1 b2 b3 J m r

b1 = 1; % drag coefficient
b2 = 0.5; % drag coefficient
b3 = 1; % drag coefficient
J = 1; % Inertia
m = 1; % mass 
r = 1 ; % radius from COM to propellor

A = [0 1 0 0;
     0 -b1/J 0 -b2/J;
     0 0 0 1;
     0 0 0 -b3/m]
 
B = [0 0;
     -r/J r/J;
     0 0;
     1/m 1/m]
 
%  C1 = ctrb(A,B) Easy function to calc the controlability matrix. Requires
%  double matrix. Does't work with sym matrix
 
 Ca = [B A*B A*A*B A*A*A*B]
 
 C = [0 1 0 0;
      0 0 0 1]
 
 O = [C C*a C*A*A C*A*A*A]'
 
 