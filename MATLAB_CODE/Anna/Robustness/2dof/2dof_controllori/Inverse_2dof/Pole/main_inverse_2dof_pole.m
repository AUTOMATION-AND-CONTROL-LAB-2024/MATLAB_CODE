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
 
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [0;0;0;0];               % State Equilibrium Vector - Roll, Pitch angles and rates

%% Linearized Model (Inverse Dynamic)
A = [zeros(2,2),    eye(2);
     zeros(2,2),    zeros(2,2);];
B = [zeros(2,2);
     eye(2);];

%% Pole Placement
% check controllability so as to place pole
if rank(ctrb(A,B))==4
    fprintf('The system is controllable\n')
end

system_poles = eig(A);
poles = -[0.13,0.14,0.15,0.16];
[Kpole ,prec]= place(A,B,poles);
save("K_inverse_2dof","Kpole");