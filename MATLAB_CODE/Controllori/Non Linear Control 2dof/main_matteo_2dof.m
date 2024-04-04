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
 
%% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
% syms k l b
% Conversion = [k      k       k       k;
%      0      0       l*k     -l*k;
%      -l*k   l*k     0       0;
%      -b     -b      b       b;]; 
% inv(Conversion)

% Da accorciare!!!!!!!!!!!!!!!!!!!!!!

%% compute the inversion matrix of J
syms J11 J12 J21 J22
syms C11 C12 C21 C22
J = [J11 J12;
     J21 J22];
% C = [C11 C12;
%      C21 C22];
invJ = inv(J);

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [0;0;0;0];               % State Equilibrium Vector - Roll, Pitch angles and rates
% w_eq          = [1000;1200;1400;2000];  % Control Input Equilibrium - Propellers' Angular Velocities

%% Linearized Model (Inverse Dynamic)
A = [zeros(2,2),    eye(2);
     zeros(2,2),    zeros(2,2);];
B = [zeros(2,2);
     eye(2);];

% check controllability so as to place pole
if rank(ctrb(A,B))==4
    fprintf('The system is controllable\n')
end


system_poles = eig(A);
poles = -[0.13,0.14,0.15,0.16];
[Kpole ,prec]= place(A,B,poles);
save("K_inverse_2dof","Kpole");
% % Robustness
% save("K_inverse_rob_2dof","Kpole");

open('InverseDynamicControl_NominalCondition_2dof.slx')
sim('InverseDynamicControl_NominalCondition_2dof.slx',Tend_slk);
