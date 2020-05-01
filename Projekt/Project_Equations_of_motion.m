clc;
clear;
syms mc mp x dx l th dth g F Fcart Fpend ddx ddth s

% mc=0.9+0.1; 
% mp=0.08887;
% l= 0.36022;
% g = 9.82;

E = [(mc+mp)*ddx + mp*l*ddth == F-Fcart, mp*l^2*ddth-mp*ddx*l-mp*g*l*th == -Fpend];
S = solve(E,ddx,ddth);
pretty(S.ddx)
pretty(S.ddth)



