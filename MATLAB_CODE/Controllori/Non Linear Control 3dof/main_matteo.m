%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;         %  gravity acceleration (m/s^2)
Ixx         =       4.856e-3;     %  moment of inertia (kg*m^2)
Iyy         =       4.856e-3;     %  moment of inertia (kg*m^2)
Izz         =       8.801e-3;     %  moment of inertia (kg*m^2)
l           =       0.225;
k           =       2.98e-7;
b           =       1.14e-7;
m           =       0.468;        %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];
 
% %% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
% syms k l b
% Conversion = [k      k       k       k;
%      0      0       l*k     -l*k;
%      -l*k   l*k     0       0;
%      -b     -b      b       b;];
% inv(Conversion)

%% compute the inversion matrix of J
syms J11 J12 J13 J21 J22 J23 J31 J32 J33
syms C11 C12 C13 C21 C22 C23 C31 C32 C33
J = [J11 J12 J13;
     J21 J22 J23;
     J31 J32 J33;];
C = [C11 C12 C13;
     C21 C22 C23;
     C31 C32 C33;];
invJ = inv(J);

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

%% Initial conditions (which correspond to the equilibrium conditions)
x0          =       [0;0;0;0;0;0];          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
% w_eq        = [1000;1200;1400;2000];  % Control Input Equilibrium - Propellers' Angular Velocities

%% Linearized Model (Inverse Dynamic)
A = [zeros(3,3),    eye(3);
     zeros(3,3),    zeros(3,3);];
B = [zeros(3,3);
     eye(3);];

% check controllability so as to place pole
if rank(ctrb(A,B))==6
    fprintf('The system is controllable\n')
end
system_poles = eig(A);
poles = -[0.1,0.12,0.13,0.14,0.15,0.16];
[Kpole ,prec]= place(A,B,poles);
save("K_inverse.mat","Kpole")