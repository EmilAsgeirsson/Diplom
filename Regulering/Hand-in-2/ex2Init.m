clc
clear
close all
%% Parameters
g = 9.82;  % Gravitational acceleration
c = 10;    % Drag coefficient
m = 900;   % Mass of vehicle
%% Operating point
vBar = 10; % Operating point speed

k = 1/2*c*vBar;
tau = m/(2*c*vBar);
%% Controller gains
close all;
Kp = 1000; % Proportional gain
Ti = 1.6;  % Integral time
s = tf('s');
K = Kp*((s+(1/Ti))/s)
[Knum, Kden] = tfdata(K);
G = k/(tau*s+1)
[Gnum, Gden] = tfdata(G);

sys = (K*G)/(1+K*G);

% sys1 = (50000*(-1) + 32150) / (4.5*(-1)^2 -1 )
% sys1 = (225000*(-1)^3 + 190625*(-1)^2 + 31250*(-1)) / (40.5*(-1)^4 + 225018*(-1)^3 + 190627*(-1)^2 + 31250*(-1))
fig = figure('Name','BodePlotMargins');
margin(sys)
movegui(fig,[-100 555]);
fig2 = figure('Name','Nyquist');
nyquist(sys)
xlim([-1.5 1.5])
ylim([-1.5 1.5])
movegui(fig2,[-100 50]);
circle(0,0,1)
fig3 = figure('Name','Open loop system');
rlocus(sys)
movegui(fig3,[600 555]);
fig4 = figure('Name','Closed Loop System');
rlocus(K*G/(1+K*G))
movegui(fig4,[600 50]);
fig5 = figure('Name','Step')
step(K*G/(1+K*G))
movegui(fig5,[0 50]);
fig6 = figure('Name','Pzmap')
pzmap(K*G/(1+K*G))
movegui(fig6,[0 555]);

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
