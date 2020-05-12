clc
clear
close all

% Model Parameters
m = 1; % Mass of link [kg]
l = 0.5; % Distance to CoM of link [m]
b = 0.1; % Joint friction coefficient [Nm/(rad/s)]
g = 9.82; % Gravitational acceleration [m/s^2]

C = [1 0 ]
A1 = [0 1;
     (cos(pi/3)*g)/l (-b/(m*l^2))]
A2 = [0 1;
     g/2*l (-b/(m*l^2))]
B = [0; 1/(m*l^2)]

nonLinSys = ss(A1,B,C,0)
ninSys = ss(A2,B,C,0)

% Root Locus Plot
s = tf('s');
Kp = 1;
Ti = 0.1;
Td = 0.025;
K = Kp * (1 + 1/(Ti*s) + Td*s);
%% Linearized
G = 2/(0.5*s^2 + 0.2*s -4.91);
%% NonLinearized
G = 1/(0.25*s^2 + 0.1*s -2.4550);
%%
H = K*G
[R,K] = rlocus(H);
polesH = pole(H);
zerosH = zero(H);


font_size=10;
width = 10;         
height = 5;
SCREEN_LEFT = 15;
SCREEN_RIGHT = 10;
ADD = 0;
figure
hold on
set(gcf,'Units','centimeters')
set(gcf,'Position',[SCREEN_LEFT  SCREEN_RIGHT  width+4*ADD  height+2*ADD])
set(gcf,'Color','w')
hold on
ax = gca;

plot([-1e6 1e6],[0 0],':k')
plot([0 0],[-1e6 1e6],':k')
ax.ColorOrderIndex = 1;
plot(R')
ax.ColorOrderIndex = 1;
plot(complex(real(polesH),imag(polesH)),'x')
ax.ColorOrderIndex = 1;
plot(complex(real(zerosH),imag(zerosH)),'o')
set(gca,'FontName','Times New Roman','FontSize',font_size);
xlabel('Re$(s)$','Interpreter','latex','FontSize',font_size)
ylabel('Im$(s)$','Interpreter','latex','FontSize',font_size)
xlim([-4 4])
ylim([-2 2])

box on

%% System Response
t = linspace(0,10);
 u = sin(t);
%u = (sqrt(3)*l*m*g)/3
y = u;
%y = 0.5*sin(t+1);

font_size=10;
width = 10;         
height = 5;
SCREEN_LEFT = 15;
SCREEN_RIGHT = 10;
ADD = 0;
figure
hold on
set(gcf,'Units','centimeters')
set(gcf,'Position',[SCREEN_LEFT  SCREEN_RIGHT  width+4*ADD  height+2*ADD])
set(gcf,'Color','w')
subplot(2,1,1)
hold on
plot(t,y)
set(gca,'FontName','Times New Roman','FontSize',font_size);
set(gca,'XTickLabel','');
ylabel('Output $y$','Interpreter','latex','FontSize',font_size)
box on
subplot(2,1,2)
hold on
plot(t,u)
set(gca,'FontName','Times New Roman','FontSize',font_size);
ylabel('Input $u$','Interpreter','latex','FontSize',font_size)
xlabel('Time $t$ [s]','Interpreter','latex','FontSize',font_size)


box on
