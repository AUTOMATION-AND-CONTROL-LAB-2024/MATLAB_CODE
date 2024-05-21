clear all
close all
clc

%% General data
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


s           =   tf('s');
Ts_slk      =   0.01;
Tend_slk    =   400;
x0          =   [0;0];          % State Equilibrium Vector - Roll angles and rates
%% PID (done together)
% G           =   1/0.055/s^2;
% 
% kd          =   1;
% kp          =   0.2;
% ki          =   0.01;
% C_matteo    =   5*0.055*(kd*s^2+kp*s+ki)/s;
% 
% L           =   G*C_matteo;
% bode(L);
% grid on;

% C=0.6026*(1+20*s)/(1+0.5*s)^2;
% C_disc=c2d(C,Ts_slk);
% 
% C_cami=(100*s^2)/(s^2+3*s);
% C_cami_discr=c2d(C_cami,Ts_slk);

%% Method 1: PID 
% G           =   1/0.055/s^2;
% 
% % response time: 1
% % robustness: 0.6
% % option: Balanced
% Kp          =   0.0408494379196507*4;
% Ki          =   0.00382471475812365;
% Kd          =   0.107131307975801;
% N           =   10.9079405084324;
% % possibilità di modificare i requisiti senza troppi problemi
%% Method 2: Inverse Dynamics
% G_inverse = 1/s^2;
% 
% % response time: 1.5
% % robustness: 0.546
% % option: Balanced
% Kp          =   1.397; % valore già moltiplicato per 4 per rigettare disturbi
% Ki          =   0.022862;
% Kd          =   1.2979;
% N           =   4.862432089028;
% 
% % In questa modalità satura a 50 e 100 (reference 0) e rigetta pochissimo
% % Disturbi sinusoidali no
%% Method 3: H2
load("stable_sys_H2_1dof_new_Ixx")

% response time: 2
% robustness: 0.9
% option: Balanced
Kp          =   0.180109037198918;
Ki          =   0.150719618455462;
Kd          =   0.0291322547663788;
N           =   114.28279760416;

% possibilità di modificare i requisiti senza troppi problemi
%% Method 4: Pole Placement
% load("system_lin0_1dof_new_Ixx") % G_pole = 1/Ixx/s^2;
% Ae      =   [ Alin, zeros(2,1);
%                 -Clin, zeros(1,1)];
% Be      =   [Blin 
%             zeros(1,1)];
% 
% K       =   place(Ae,Be,[-0.8 -0.9 -1]); 
% 
% Kx      =   K(:,1:2);
% Kv      =   K(:,3);

