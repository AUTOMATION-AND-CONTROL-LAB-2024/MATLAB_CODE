%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;               %  gravity acceleration (m/s^2)
Ixx         =       0.015;              %  moment of inertia (kg*m^2)
Iyy         =       0.015;              %  moment of inertia (kg*m^2)
Izz         =       0.03;               %  moment of inertia (kg*m^2)
l           =       0.25;               %  quadcopter arm (m)
k           =       0.0022;             %  lift constant
b           =       1.14e-7;            %  drag constant
m           =       0.61+0.064*4;     %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];

% %% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
% syms k l b
% Conversion = [k      k       k       k;
%      0      0       l*k     -l*k;
%      -l*k   l*k     0       0;
%      -b     -b      b       b;];
% inv(Conversion);

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;0]*0.01;          % State Equilibrium Vector - Roll angles and rates
tau_eq      = [0];            % Control Input Equilibrium - Roll torque
%% Desired values
x_des       = [1;0];          % notice that is scaled in simulation! 
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s)
%% Linearization
% sim('Modello_corretto_1dof.slx',Tend_slk);
% 
% mdl         = 'Modello_corretto_1dof';
% open_system(mdl)
% blockpath   = 'Modello_corretto_1dof/G';
% linsys      = linearize(mdl,blockpath);
% 
% Alin=linsys.A;
% Blin=linsys.B;
% Clin=linsys.C;
% Dlin=linsys.D;
% save("system_lin0_1dof","Alin","Blin","Clin","Dlin");
load("system_lin0_1dof.mat")

%% H2 infinity
% rounding_n      =   3;                  % rounding at the nth decimal place
% % Difm            =   di_fixed_modes(Alin,Blin,Clin,rounding_n);
% [K,feas,ris]        =   H2_control_1dof(Alin,Blin,Clin,Dlin);
load("K_H2_1dof.mat")

% Transfer function between gamma and y
s=tf('s')
A_cl=Alin+Blin*K;
stable_sys= Clin*inv(s*eye(2)-A_cl)*Blin;      
eig(stable_sys)         

% PI controller to obtain desired performances
% Kp              =   0.0006586;
% Ki              =   0.0006581;
% Kd              =   0.0001648;
% save("PI","Kp","Ki","Kd")
load("PI.mat")

% open("H2_control_1dof.slx")
% sim("H2_control_1dof.slx",Tend_slk)
%% trial to reduce disturbances
C = Kp+Ki/s+Kd*s;
D = stable_sys/(1+stable_sys*C); % transfer function between output and disturbance
pzmap(D)
[K,feas,ris]        =   H2_control_1dof(Alin,Blin,Clin,Dlin);
save("K_H2_robustness_1dof","K")

s=tf('s')
A_cl=Alin+Blin*K;
stable_sys= Clin*inv(s*eye(2)-A_cl)*Blin;      
eig(stable_sys) 

% PI controller to obtain desired performances
Kp              =   0.000271; %150 s
Ki              =   0.0001274;
Kd              =   0.0001441;
save("PI_robust","Kp","Ki","Kd")