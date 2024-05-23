%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062];     %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)
Ixx         =       0.015;                  %  moment of inertia (kg*m^2)
Iyy         =       0.015;                  %  moment of inertia (kg*m^2)
Izz         =       0.03;                   %  moment of inertia (kg*m^2)
l           =       0.25;                   %  quadcopter arm (m)
k1          =       0.00684324;             %  lift constant motor 1
k2          =       0.00703859;             %  lift constant motor 2
k3          =       0.00814964;             %  lift constant motor 3
k4          =       0.00746697;             %  lift constant motor 4
b           =       1.14e-7;                %  drag constant
m           =       0.61+0.064*4;           %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k1;k2;k3;k4;b;m];

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;0]*0.01;          % State Equilibrium Vector - Roll angles and rates
tau_eq      = [0];            % Control Input Equilibrium - Roll torque

%% Desired values
x_des       = [1;0];          % notice that is scaled in simulation! 

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

%% VSC
s=tf('s');
% load("system_lin0_1dof.mat")
% Glin= Clin*inv(s*eye(2)-Alin)*Blin; 
% bode(Glin)
A   =[0 1;
      0 0];
B   =[0;
      1];
C   =[66.67 0];
D   =[0];
G   = C*inv(s*eye(2)-A)*B+D; 
% bode(G)

% check observability 
if rank(obsv(A,C))==2
    fprintf('The system is observable\n ')
end

% check controllability 
if rank(ctrb(A,B))==2
    fprintf('The system is controllable\n ')
end

% beta_t    =   [0.5 1];
% alpha_t   =   beta_t*A;
% gamma   =   0.5;
% r       =   1;
% t_reach =   1;
% y_des   =   0.5/0.5;
% W       =   0.2;
% q       =   7.5e-3*y_des/t_reach+W;

beta1    = 0.15;
beta_t    =   [beta1 1];
alpha_t   =   beta_t*A;
gamma   =   beta1/C(1,1);
r       =   1;
t_reach =   1;
y_des   =   0.5;
W       =   0.2;
q       =   (abs(beta1*x0(1,1)+x0(1,1)-gamma*y_des)/t_reach)+W;


%% parameter uncertainty 
epsilon     = 100; % più è piccolo, più il transitorio è lento

%% high frequency input switching

F = [A B;
    zeros(1,2) zeros(1,1)];
G = [0;0;1];
H =[C 0];

beta_t_en   =   [0.25 1 1];
alpha_t_en   =   beta_t_en*F;
gamma_en = beta_t_en(1,1)/H(1,1);

q_en       =   (abs(-gamma_en*y_des)/t_reach)+W;


% n=2
% S_en_old = ss(F,G,H,0)
% G_en = tf(S_en_old);
% S_en_can = ss([zeros(n,1), eye(n); -G_en.Denominator{1,1}(end), -G_en.Denominator{1,1}(end-1), -G_en.Denominator{1,1}(end-2)] ...
%     ,[zeros(n,1); 1] ...
%     ,[G_en.Numerator{1,1}(end), G_en.Numerator{1,1}(end-1), G_en.Numerator{1,1}(end-2)] ...
%     ,[0]);
% 
% F_tilde = S_en_can.A;
% G_tilde = S_en_can.B;
% H_tilde = S_en_can.C;
% D_tilde = S_en_can.D;
% 
% % T= inv(inv(H)*H_tilde)
% Mc=ctrb(F,G)
% Mc_tilde=ctrb(F_tilde,G_tilde)
% T= Mc_tilde*inv(Mc) %% è un indentità. infatti il sistema allargato originale era già in controllable canonical form