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
% syms J11 J12 J13 J21 J22 J23 J31 J32 J33
% syms C11 C12 C13 C21 C22 C23 C31 C32 C33
% J = [J11 J12 J13;
%      J21 J22 J23;
%      J31 J32 J33;];
% C = [C11 C12 C13;
%      C21 C22 C23;
%      C31 C32 C33;];
% invJ = inv(J);

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;1;0;0;0]*0.01;          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
tau_eq      = [0;0;0];                % Control Input Equilibrium - Roll, Pitch, Yaw torques

%% Desired values
x_des       = [1;1;1;0;0;0];          % notice that is scaled in simulation!
%% Simulation of the model with random parameters
Ts_slk      =       0.01;             % sampling time (s)
Tend_slk    =       400;              % simulation time (s)

%% Linearize the system
% sim('Modello_corretto.slx',Tend_slk);
% 
% mdl         = 'Modello_corretto';
% open_system(mdl)
% blockpath   = 'Modello_corretto/G';
% linsys      = linearize(mdl,blockpath);
% Alin =linsys.A;
% Blin =linsys.B;
% Clin =linsys.C;
% save("system_lin0","Alin", "Blin", "Clin");
load("system_lin0.mat")
%% Pole placement + observer
% pzmap(ss(linsys.A,linsys.B,linsys.C,linsys.D))

% check observability so as to compute observer
if rank(obsv(Alin,Clin))==6
    fprintf('The system is observable\n')
end
L       =   place(Alin',Clin',[-50.7 -50.6 -50.5 -50.4 -50.3 -50.2])';

% check controllability so as to place pole
if rank(ctrb(Alin,Blin))==6
    fprintf('The system is controllable\n ')
end

% design the enlarged system
Ae      =   [ Alin, zeros(6,3);
                -Clin, zeros(3,3)];
Be      =   [Blin 
            zeros(3,3)];

if rank(ctrb(Ae,Be))==9
    fprintf('The enlarged system is controllable\n ')
end

load("K_pole.mat")
% K       =   place(Ae,Be,[-0.06 -0.07 -0.02 -0.03 -0.04 -0.05 -0.08 -0.09 -0.1]);
% 
% Kx      =   K(:,1:6);
% Kv      =   K(:,7:9);
% save("K_pole_slow1","Kx","Kv")

open('pole_placement.slx')
sim('pole_placement.slx',Tend_slk);
