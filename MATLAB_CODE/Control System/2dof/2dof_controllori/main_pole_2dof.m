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
tau_eq      = [0;0];              % Control Input Equilibrium - Roll, Pitch torques

%% Desired values
x_des       = [1;1;0;0];          % notice that is scaled in simulation!
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

%% Pole placement + observer
% pzmap(ss(linsys.A,linsys.B,linsys.C,linsys.D))

% check observability so as to compute observer
if rank(obsv(Alin,Clin))==4
    fprintf('The system is observable\n')
end
L       =   place(Alin',Clin',[-50.7 -50.6 -50.5 -50.4])';

% check controllability so as to place pole
if rank(ctrb(Alin,Blin))==4
    fprintf('The system is controllable\n ')
end

% design the enlarged system
Ae      =   [ Alin, zeros(4,2);
                -Clin, zeros(2,2)];
Be      =   [Blin
            zeros(2,2)];

if rank(ctrb(Ae,Be))==6
    fprintf('The enlarged system is controllable\n ')
end
  
K       =   place(Ae,Be,[-0.11 -0.12 -0.13 -0.14 -0.15 -0.1]);

Kx      =   K(:,1:4);
Kv      =   K(:,5:6);
save("K_pole_2dof","Kx","Kv")

open('pole_placement_2dof.slx')
sim('pole_placement_2dof.slx',Tend_slk);
