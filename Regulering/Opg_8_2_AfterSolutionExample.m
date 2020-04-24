clc;
clear;
close all;
% Exercise 8.2
s = tf('s');
G = 1/(s*(s+1));
T = 1/100; % sample time
[Gnum, Gden] = tfdata(G);
Gd = 1/(T/2*s+1); % Delay
[Gdnum, Gdden] = tfdata(Gd);

figure
rlocus(G*Gd)

figure
Td = 1;
rlocus(G*Gd*(Td*s+1))

Kp = 5;
N = 30;
K = Kp*(1+N-N/(1+s*Td/N))

[Knum, Kden] = tfdata(K);

figure
H = K*G*Gd / (1+K*G*Gd);
step(H)
figure
bodemag(H)

z = tf('z');
TM = 2/T*(z-1)/(z+1);
Kd = Kp*(1+N-N/(1+TM*Td/N))

[Kdnum, Kdden] = tfdata(Kd);
