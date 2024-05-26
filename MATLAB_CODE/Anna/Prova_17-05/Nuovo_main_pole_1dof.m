%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)
Ixx         =       0.055;                  %  moment of inertia (kg*m^2)
Iyy         =       0.055;                  %  moment of inertia (kg*m^2)
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
%% Linearization
% sim('Modello_corretto_1dof.slx',Tend_slk);
% 
% mdl         = 'Modello_corretto_1dof';
% open_system(mdl)
% blockpath   = 'Modello_corretto_1dof/G';
% linsys      = linearize(mdl,blockpath);
% 
% Alin=linsys.A;
% Blin=linsys.B;
% Clin=linsys.C;
% Dlin=linsys.D;
% save("system_lin0_1dof","Alin","Blin","Clin","Dlin");
load("system_lin0_1dof_new_Ixx.mat")

%% Pole placement + observer
% pzmap(ss(linsys.A,linsys.B,linsys.C,linsys.D))

% % check observability so as to compute observer
% if rank(obsv(Alin,Clin))==2
%     fprintf('The system is observable\n ')
% end
% L       =   place(Alin',Clin',[-50.7 -50.6])';

% check controllability so as to place pole
if rank(ctrb(Alin,Blin))==2
    fprintf('The system is controllable\n ')
end

% design the enlarged system
Ae      =   [ Alin, zeros(2,1);
                -Clin, zeros(1,1)];
Be      =   [Blin 
            zeros(1,1)];

if rank(ctrb(Ae,Be))==3
    fprintf('The enlarged system is controllable\n ')
end
  
% K       =   place(Ae,Be,[-0.11 -0.12 -0.13]);
% 
% Kx      =   K(:,1:2);
% Kv      =   K(:,3);
load("K_pole_1dof_new_Ixx","Kx","Kv")

% open("pole_placement_1dof.slx")
% sim("pole_placement_1dof.slx",Tend_slk)