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
m           =       0.61+0.064*4;       %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];

% %% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
% syms k l b
% Conversion = [k      k       k       k;
%      0      0       l*k     -l*k;
%      -l*k   l*k     0       0;
%      -b     -b      b       b;];
% inv(Conversion);
% 
% %% compute the inversion matrix of J
% syms J11 J12 J21 J22
% syms C11 C12 C21 C22
% J  = [J11 J12;
%       J21 J22];
% C  = [C11 C12;
%       C21 C22];
% invJ = inv(J);

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;0;0]*0.01;          % State Equilibrium Vector - Roll, Pitch angles and rates
tau_eq      = [0;0];                   % Control Input Equilibrium - Roll, Pitch torques

%% Desired values
x_des       = [1;1;0;0];               % notice that is scaled in simulation!
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s)

%% Linearize the system
% sim('Modello_corretto_2dof.slx',Tend_slk);
% 
% mdl         = 'Modello_corretto_2dof';
% open_system(mdl)
% blockpath   = 'Modello_corretto_2dof/G';
% linsys      = linearize(mdl,blockpath);
% 
% Alin=linsys.A;
% Blin=linsys.B;
% Clin=linsys.C;
% Dlin=linsys.D;
% save("system_lin0_2dof","Alin","Blin","Clin","Dlin");
load("system_lin0_2dof.mat")


%% H2 infinity
rounding_n      =   3;                  % rounding at the nth decimal place
% Difm            =   di_fixed_modes(linsys.A,linsys.B,linsys.C,rounding_n);
[K,feas,ris]        =   H2_control_2dof(Alin,Blin,Clin,Dlin);
save("K_H2_2dof","K")

% Transfer function between gamma and y
s               =   tf('s')
A_cl            =   Alin+Blin*K;
stable_sys      =   Clin*inv(s*eye(4)-A_cl)*Blin;      
eig(stable_sys)            
stable_sys_disc = c2d(stable_sys, Ts_slk)
% Standard formulation for a decoupler
Decoupler       =   [1 -stable_sys(1,2)/stable_sys(1,1);
                    -stable_sys(2,1)/stable_sys(2,2) 1];
Decoupler_disc  = c2d(Decoupler,Ts_slk)
save("Decoupler_2dof","Decoupler")
save("Decoupler_2dof_disc","Decoupler_disc")

% Complete transfer function ( Diagonal thanks to the chosen structure of
% the decoupler) on which we have to build the PI controllers
Gdes            =   stable_sys*Decoupler;                       

% PI controllers tuning (controllers are decoupled) to obtain desired
% performances
Gdes11          =   Gdes(1,1); 
Kp11            =   0.001625;
Ki11            =   0.001599;
Kd11            =   0.0004126;
save("PI1","Kp11","Ki11","Kd11")

Gdes22          =   Gdes(2,2);
Kp22            =   0.001628;
Ki22            =   0.001599;
Kd22            =   0.0004141;
save("PI2","Kp22","Ki22","Kd22")

open("H2_control_2dof.slx")
sim("H2_control_2dof.slx",Tend_slk)
