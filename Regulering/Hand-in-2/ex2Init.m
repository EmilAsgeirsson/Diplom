clc
clear
close all
%% Parameters
g = 9.82;  % Gravitational acceleration
c = 10;    % Drag coefficient
m = 900;   % Mass of vehicle
%% Operating point
vBar = 10; % Operating point speed
Ts = 0.1406; % Sample time

k = 1/(2*c*vBar)
tau = m/(2*c*vBar)
%% Controller gains
close all;
Kp = 1000; % Proportional gain
Ti = 1.6;  % Integral time
s = tf('s');
K = Kp*((s+(1/Ti))/s)
[Knum, Kden] = tfdata(K);
G = k/(tau*s+1)
[Gnum, Gden] = tfdata(G);
Gd = 1/((Ts/2)*s+1)
[Gdnum, Gdden] = tfdata(Gd);
% sys = K*G/(1+K*G)
sys = K*G*Gd

% sys1 = (50000*(-1) + 32150) / (4.5*(-1)^2 -1 )
% sys1 = (225000*(-1)^3 + 190625*(-1)^2 + 31250*(-1)) / (40.5*(-1)^4 + 225018*(-1)^3 + 190627*(-1)^2 + 31250*(-1))
fig = figure('Name','BodePlotMargins');
margin(sys);
movegui(fig,[-100 555]);
saveas(fig,'BodePlotWithValues.jpg');
fig2 = figure('Name','Nyquist');
nyquist(sys);
xlim([-1.5 1.5]);
ylim([-1.5 1.5]);
movegui(fig2,[-100 50]);
circle(0,0,1);
saveas(fig2,'VectorMargin2.jpg')
fig3 = figure('Name','Open loop system');
rlocus(sys);
movegui(fig3,[600 555]);
fig4 = figure('Name','Closed Loop System');
rlocus(K*G/(1+K*G));
movegui(fig4,[600 50]);
fig5 = figure('Name','Step');
step(K*G/(1+K*G));
movegui(fig5,[0 50]);
fig6 = figure('Name','Pzmap');
pzmap(K*G/(1+K*G));
movegui(fig6,[0 555]);
saveas(fig6,'PZMap.jpg');

function h = circle(x,y,r)
hold on
th = 0:pi/50:2*pi;
xunit = r * cos(th) + x;
yunit = r * sin(th) + y;
h = plot(xunit, yunit, ':');
hold off
end
%% Test
% bla = (k*Kp*(s+1/Ti))/(tau*s^2+(1+k*Kp)*s+(k*Kp/Ti))
%% Calculations of the entire discrete system.
% syms Kp s Ti k tau Ts
% K = Kp*(s+(1/Ti))/s;
% pretty(K)
% G = k/(tau*s+1);
% pretty(G)
% Gd = 1/((Ts/2)*s+1);
% pretty(Gd)
% 
% H = K*G*Gd;
% pretty(H)
