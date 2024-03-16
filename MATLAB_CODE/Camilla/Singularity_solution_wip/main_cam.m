%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;         % gravity acceleration (m/s^2)
Ixx         =       4.856e-3;     %  moment of inertia
Iyy         =       4.856e-3;     %  moment of inertia (kg*m^2)
Izz         =       8.801e-3;     %  moment of inertia (kg*m^2)
l           =       0.225;
k           =       2.98e-7;
b           =       1.14e-7;
m           =       0.468;        %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];
 
% cph         =       cos(phi);
% cth         =       cos(theta);
% cps         =       cos(psi);
% sph         =       sin(phi);
% sth         =       sin(theta);
% sps         =       sin(psi);

%% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
syms k l b
ConvMatrix = [k      k       k       k;
     0      0       l*k     -l*k;
     -l*k   l*k     0       0;
     -b     -b      b       b;];
inv(ConvMatrix);

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       10;                % final time (s)

%% Initial conditions (which correspond to the equilibrium conditions)
x_eq          = [0;0;0;0;0;0];          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
% tau_m_eq      = [1;1;1;1];              % Input Equilibrium - Motor Torque
w_eq          = [1000;1200;1400;2000];  % Control Input Equilibrium - Propellers' Angular Velocities

%% Linearize the system using Simulink Control Design
% Run simulation
QuattroCopter       = sim('sim_cam_1.slx',Tend_slk);

mdl         = 'sim_cam_1';
open_system(mdl)
blockpath   = 'sim_cam_1/Model';
linsys      = linearize(mdl,blockpath);