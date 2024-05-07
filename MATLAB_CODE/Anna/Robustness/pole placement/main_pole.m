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

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;1;0;0;0]*0.01;     % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
tau_eq      = [0;0;0];                % Control Input Equilibrium - Roll, Pitch, Yaw torques

%% Desired values
x_des       = [1;1;1;0;0;0];          % notice that is scaled in simulation!
%% Simulation of the model with random parameters
Ts_slk      =       0.01;             % sampling time (s)
Tend_slk    =       400;              % simulation time (s)

%% Linearize the system
% sim('Modello_corretto_for_disturbance.slx',Tend_slk);
% 
% mdl         = 'Modello_corretto_for_disturbance';
% open_system(mdl)
% blockpath   = 'Modello_corretto_for_disturbance/G';
% linsys      = linearize(mdl,blockpath);
% Alin =linsys.A;
% Blin =linsys.B;
% Clin =linsys.C;
% Dlin =linsys.D;
% save("system_lin0_robust","Alin", "Blin", "Clin", "Dlin");
% Dlin=zeros(3,3);
load("system_lin0_robust.mat") %% è stato modificato con 6 output

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

% design the enlarged system % modificato con 6 output
Ae      =   [ Alin, zeros(6,6);
                -Clin, zeros(6,6)];
Be      =   [Blin 
            zeros(6,3)];

if rank(ctrb(Ae,Be))==12
    fprintf('The enlarged system is controllable\n ')
end
% NON è CONTROLLABLE

K       =   place(Ae,Be,[-0.06 -0.07 -0.02 -0.03 -0.04 -0.05 -0.08 -0.09 -0.1]);

Kx      =   K(:,1:6);
Kv      =   K(:,7:9);
% save("K_pole_slow1","Kx","Kv")
% load("K_pole.mat")
open('pole_placement_with_disturbance.slx')
% sim('pole_placement_with_disturbance.slx',Tend_slk);


%% Robustness 
% 6 output
M   =   [1 0 0 ;
         0 1 0 ;
         0 0 1 ;
         zeros(3,3)];
N   =   [0 0 0 ;
         0 0 0 ;
         0 0 0 ;
         zeros(3,3)];
A_r =   [Alin M;
        zeros(3,6) zeros(3,3)];
C_r =   [eye(6) N];

B_r =   [Blin; zeros(3,3)]

D_r =   zeros(6,3);

if rank([Alin M; eye(6) N])==9
    fprintf('We can estimate constant disturbances\n ')
end

L_r       =   place(A_r',C_r',[-50.7 -50.6 -50.5 -50.4 -50.3 -50.2 -50.1 -50 -49.9])';

% M   =   [1 0 0 ;
%          0 1 0 ;
%          0 0 0 ;
%          zeros(3,3)];
% 
% N   =   [0 0 0 ;
%          0 0 0 ;
%          0 0 0 ];
% 
% A_r =   [Alin M;
%         zeros(3,6) zeros(3,3)];
% 
% C_r =   [eye(3) N];
% 
% B_r =   [Blin; zeros(3,3)];
% 
% D_r =  Dlin;
% 
% if rank([Alin M;Clin N])==9
%     fprintf('We can estimate constant disturbances\n ')
% else fprintf('We CANNOT estimate constant disturbances\n ')
% end
