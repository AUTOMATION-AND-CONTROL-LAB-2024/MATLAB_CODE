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
% CHI             =   conv([1 0.02],conv([1 0.03],conv([1 0.04],conv([1 0.05],conv([1 0.06],conv([1 0.07],conv([1 0.08],[1 0.09])))))));
% beta            =   CHI(2:end);
s=tf('s')
% load("system_lin0_1dof.mat")
% Glin= Clin*inv(s*eye(2)-Alin)*Blin; 
% bode(Glin)
A   =[0 1;
      0 0];
B   =[0;
      1];
C   =[66.67 0];
G   = C*inv(s*eye(2)-A)*B; 
% bode(G)


beta    =   [0.5 1];
alpha   =   beta*A;
gamma   =   0.5;
r       =   1;
t_reach =   1;
y_des   =   0.5/0.5;
W       =   0.2;
q       =   7.5e-3*y_des/t_reach+W;
