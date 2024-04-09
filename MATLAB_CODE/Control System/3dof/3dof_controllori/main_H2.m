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
m           =       (0.61+0.064*4);     %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;1;0;0;0]*0.01;          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
tau_eq        = [0;0;0];
%% Desired values
x_des         = [1;1;1;0;0;0];
%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s)

%% Linearize the system
load("system_lin0.mat")
%% H2 infinity
rounding_n      =   3;
% Difm            =   di_fixed_modes(Alin,Blin,Clin,rounding_n);
[K,feas,ris]        =    H2_control(Alin,Blin,Clin);
save("K_H2","K")

s=tf('s')
A_cl            =   Alin+Blin*K;
stable_sys      =   Clin*inv(s*eye(6)-A_cl)*Blin;      
eig(stable_sys) %%  transfer function between gamma and y

G = [stable_sys(1,1) stable_sys(1,2) stable_sys(1,3);
     stable_sys(2,1) stable_sys(2,2) stable_sys(2,3);
     stable_sys(3,1) stable_sys(3,2) stable_sys(3,3)];
G11= G(1,1);
G12= G(1,2);
G13= G(1,3);
G21= G(2,1);
G22= G(2,2);
G23= G(2,3);
G31= G(3,1);
G32= G(3,2);
G33= G(3,3);
Gdes = [G11 0 0;
         0 G22 0;
         0 0 G33];

% detG = G11*(G22*G33-G23*G32)-G12*(G21*G33-G23*G31)+G13*(G21*G32-G22*G31);
Decoupler=inv(G)*Gdes
save("Decoupler","Decoupler")
% Decoupler = [G11*(G22*G33-G32*G23) G22*(-G12*G33+G13*G32) G33*(G12*G23-G13*G22);
%     G11*(-G21*G33+G23*G31) G22*(G11*G33-G13*G31) G33*(-G11*G23+G13*G21);
%     G11*(G21*G32-G22*G31) G22*(-G11*G32+G12*G31) G33*(G11*G22-G12*G21)]*(detG)^(-1)

% PI controllers tuning (controllers are decoupled) to obtain desired
% performances
%G11
Kp11            =   7.045e-05;
Ki11            =   9.394e-06;
Kd11            =   1.321e-04;
save("PI1","Kp11","Ki11","Kd11")

%G22
Kp22            =   7.045e-05;
Ki22            =   9.392e-06;
Kd22            =   1.321e-04;
save("PI2","Kp22","Ki22","Kd22")

%G33
Kp33            =   4.984e-05;
Ki33            =   4.462e-06;
Kd33            =   1.392e-04;
save("PI3","Kp33","Ki33","Kd33")

% Gamma = [0 -G21/G22 -G31/G33;
%     -G12/G11 0 -G32/G33;
%     -G13/G11 -G23/G22 0];
% Decoupler =inv(eye(3)-Gamma);

% D12=-((G13*G32-G12*G33)/(G13*G31-G11*G33));
% D32=-((G12*G31-G11*G32)/(G13*G31-G11*G33));
% D13=(G13*G22-G12*G23)/(G12*G21-G11*G22);
% D23=-((G13*G21-G11*G23)/(G12*G21-G11*G22));
% D21=-((G23*G31-G21*G33)/(G23*G32-G22*G33));
% D31=(G22*G31-G21*G32)/(G23*G32-G22*G33);
% Decoupler = [1 D12 D13;
%             D21 1 D23;
%             D31 D32 1];
% Gdes=G*Decoupler




open("H2_control.slx")
sim("H2_control.slx",Tend_slk)
