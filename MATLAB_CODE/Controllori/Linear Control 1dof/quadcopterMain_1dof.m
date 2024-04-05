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
m           =       0.61+0.064*4;     %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];

% %% compute the inversion of matrix H: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = H * (u1,u2,u3,u4)'
% syms k l b
% Conversion = [k      k       k       k;
%      0      0       l*k     -l*k;
%      -l*k   l*k     0       0;
%      -b     -b      b       b;];
% inv(Conversion);

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [0;0];          % State Equilibrium Vector - Roll angles and rates
tau_eq      = [0];            % Control Input Equilibrium - Roll torque
%% Desired values
x_des       = [1;0];          % notice that is scaled in simulation! 
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s)
%% Linearization
sim('Modello_corretto_1dof.slx',Tend_slk);

mdl         = 'Modello_corretto_1dof';
open_system(mdl)
blockpath   = 'Modello_corretto_1dof/G';
linsys      = linearize(mdl,blockpath);

%% H2 infinity
rounding_n      =   3;                  % rounding at the nth decimal place
Difm            =   di_fixed_modes(linsys.A,linsys.B,linsys.C,rounding_n);
[K,feas]        =   H2_control_1dof(linsys.A,linsys.B,linsys.C,linsys.D);
save("K_H2_1dof.mat","K")

% Transfer function between gamma and y
s=tf('s')
A_cl=linsys.A+linsys.B*K;
stable_sys= linsys.C*inv(s*eye(2)-A_cl)*linsys.B;      
eig(stable_sys)         

% PI controller to obtain desired performances
Kp              =   0.1476;
Ki              =   0.1464;
Kd              =   0;
save("PI","Kp","Ki","Kd")

open("H2_control_sim_1dof.slx")
sim("H2_control_sim_1dof.slx",Tend_slk)
%% Pole placement + observer
% pzmap(ss(linsys.A,linsys.B,linsys.C,linsys.D))

% check observability so as to compute observer
if rank(obsv(linsys.A,linsys.C))==2
    fprintf('The system is observable\n ')
end
L       =   place(linsys.A',linsys.C',[-50.7 -50.6])';

% check controllability so as to place pole
if rank(ctrb(linsys.A,linsys.B))==2
    fprintf('The system is controllable\n ')
end

% design the enlarged system
Ae      =   [ linsys.A, zeros(2,1);
                -linsys.C, zeros(1,1)];
Be      =   [linsys.B 
            zeros(1,1)];

if rank(ctrb(Ae,Be))==3
    fprintf('The enlarged system is controllable\n ')
end
  
K       =   place(Ae,Be,[-0.11 -0.12 -0.13]);

Kx      =   K(:,1:2);
Kv      =   K(:,3);
save("K_pole_1dof","Kx","Kv")

open("pole_placement_1dof.slx")
sim("pole_placement_1dof.slx",Tend_slk)