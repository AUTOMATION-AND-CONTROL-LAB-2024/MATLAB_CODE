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

%% compute the inversion matrix of J
% syms J11 J12 J21 J22
% syms C11 C12 C21 C22
% J = [J11 J12;
%      J21 J22];
% invJ = inv(J);

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
C = [eye(2) zeros(2,2)];

%% PID
s=tf('s');
G = C*inv(s*eye(4)-A)*B;

Decoupler       =   [1 -G(1,2)/G(1,1);
                    -G(2,1)/G(2,2) 1];
save("Decoupler_inverse_2dof","Decoupler")

Gdes            =   G*Decoupler;                       

% PI controllers tuning (controllers are decoupled) to obtain desired
% performances
Gdes11          =   Gdes(1,1); 
Kp11            =   ;
Ki11            =   ;
Kd11            =   ;
save("PI1_inverse","Kp11","Ki11","Kd11")

Gdes22          =   Gdes(2,2);
Kp22            =   ;
Ki22            =   ;
Kd22            =   ;
save("PI2_inverse","Kp22","Ki22","Kd22")


