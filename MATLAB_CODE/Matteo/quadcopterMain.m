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
% 
% cph         =       cos(phi);
% cth         =       cos(theta);
% cps         =       cos(psi);
% sph         =       sin(phi);
% sth         =       sin(theta);
% sps         =       sin(psi);

%% Initial conditions (which correspond to the equilibrium conditions)
x_eq          = [0;0;0;0;0;0];          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
% tau_m_eq      = [1;1;1;1];              % Input Equilibrium - Motor Torque
w_eq          = [1000;1200;1400;2000];  % Control Input Equilibrium - Propellers' Angular Velocities
%% Desired values
x_des         = [10;12;10;15;20;25];
% tau_m_des     = [2;3;4;5];

%% Inputs
% tau_m         = []; % 4x1
%% Estimation of parameters
% J_est         = [];
% C_est         = [];
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       10;                % final time (s)
%% PD Control
ctrl_gains    = [1.75;1.75;1.75;6;6;6]; % derivative and proportional
% Linearize the system using Simulink Control Design
% Run simulation
% sim('PD_control.slx',Tend_slk);
% 
% mdl         =   'PD_control';
% open_system(mdl)
% blockpath   =   'PD_control/G/conversion2';
% linsys      =   linearize(mdl,blockpath);
% s           =   tf('s');
% sys         =   linsys.C*inv(s*eye(6)-linsys.A)*linsys.B+linsys.D
%% Kalman Filtering


% %% Linearize the system using Simulink Control Design
% % Run simulation
% sim('quadcopterSim.slx',Tend_slk);
% 
% mdl         = 'quadcopterSim';
% open_system(mdl)
% blockpath   = 'quadcopterSim/Subsystem';
% linsys      = linearize(mdl,blockpath);
%% H2 infinity
% rounding_n      =   3;
% Difm            =   di_fixed_modes(linsys.A,linsys.B,linsys.C,rounding_n);
% [K,feas]        =   H2_control(linsys.A,linsys.B,linsys.C,linsys.D);

%% Linearize the system
sim('PD_control.slx',Tend_slk);

mdl         = 'PD_control';
open_system(mdl)
blockpath   = 'PD_control/G';
linsys      = linearize(mdl,blockpath);

%% Pole placement + observer
pzmap(ss(linsys.A,linsys.B,linsys.C,linsys.D))

% check observability so as to compute observer
if rank(obsv(linsys.A,linsys.C))==6
    fprintf('The enlarged system is observable')
end
L       =   place(linsys.A',linsys.C',[-100 -90 -80 -70 -75 -85])';

% check controllability so as to place pole
if rank(ctrb(linsys.A,linsys.B))==6
    fprintf('The enlarged system is controllable')
end

% design the enlarged system
Ae      =   [ linsys.A, zeros(6,6);
                -linsys.C, zeros(6,6)];
Be      =   [linsys.B; zeros(6,4)];

if rank(ctrb(Ae,Be))==12
    fprintf('The enlarged system is controllable')
end

K       =   place(Ae,Be,[-100 -90 -80 -70 -60 -50 -40 -30 -20 -10 -25 -45]);
% Non riesco a usare place. Forse perchè il sistema allargato è quasi uncontrollable 
% per il brutto condizionamento dei valori singolari -->svd(ctrb(Ae,Be))

Kx      =   K(1:6);
Kv      =   K(end);




