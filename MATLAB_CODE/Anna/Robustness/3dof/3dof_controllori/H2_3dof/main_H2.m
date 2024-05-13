%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)
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
x0          = [1;1;1;0;0;0]*0.01;          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
tau_eq        = [0;0;0];
%% Desired values
x_des         = [1;1;1;0;0;0];
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s)

%% Linearize the system
load("system_lin0.mat")
%% H2 infinity
% rounding_n      =   3;
% % Difm            =   di_fixed_modes(Alin,Blin,Clin,rounding_n);
% [K,feas,ris]        =    H2_control_lmi(Alin,Blin,Clin);
% save("K_H2","K")
load("K_H2.mat")

s=tf('s')
A_cl            =   Alin+Blin*K;
stable_sys      =   Clin*inv(s*eye(6)-A_cl)*Blin;      
eig(stable_sys) %%  transfer function between gamma and y
stable_sys_disc  = c2d(stable_sys,Ts_slk)
% save("stable_sys_disc","stable_sys_disc")
G = [stable_sys(1,1) stable_sys(1,2) stable_sys(1,3);
     stable_sys(2,1) stable_sys(2,2) stable_sys(2,3);
     stable_sys(3,1) stable_sys(3,2) stable_sys(3,3)];
G11= G(1,1);
G12= G(1,2);
G13= G(1,3);
G21= G(2,1);
G22= G(2,2);
G23= G(2,3);
G31= G(3,1);
G32= G(3,2);
G33= G(3,3);
Gdes = [G11 0 0;
         0 G22 0;
         0 0 G33];

Decoupler=inv(G)*Gdes
% save("Decoupler","Decoupler")
Decoupler_disc  = c2d(Decoupler,Ts_slk)
% save("Decoupler_disc","Decoupler_disc")

% PI controllers tuning (controllers are decoupled) to obtain desired performances
% %G11
% Kp11            =   7.045e-05;
% Ki11            =   9.394e-06;
% Kd11            =   1.321e-04;
% % save("PI1","Kp11","Ki11","Kd11")
% 
% %G22
% Kp22            =   7.045e-05;
% Ki22            =   9.392e-06;
% Kd22            =   1.321e-04;
% % save("PI2","Kp22","Ki22","Kd22")
% 
% %G33
% Kp33            =   4.984e-05;
% Ki33            =   4.462e-06;
% Kd33            =   1.392e-04;
% % save("PI3","Kp33","Ki33","Kd33")
%G11
Kp11            =   2.122e-04; %50
Ki11            =   2.729e-05;
Kd11            =   4.127e-04;


%G22
Kp22            =   2.122e-04;
Ki22            =   2.729e-05;
Kd22            =   4.127e-04;


%G33
Kp33            =   1.496e-04;
Ki33            =   1.232e-05;
Kd33            =   4.538e-04;
