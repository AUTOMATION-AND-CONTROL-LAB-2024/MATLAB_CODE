clear all
close all
clc

%% Define some useful quantities

% Parameters
g        =       9.81;                  %  gravity acceleration (m/s^2)
Ixx         =       0.015;              %  moment of inertia (kg*m^2)
Iyy         =       0.015;              %  moment of inertia (kg*m^2)
Izz         =       0.03;               %  moment of inertia (kg*m^2)
l           =       0.25;               %  quadcopter arm (m)
k           =       0.0022;             %  lift constant
b           =       1.14e-7;            %  drag constant
m           =       0.61+0.064*4;       %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];

Ts_slk      =       0.1;              % sampling time (s)
Tend_slk    =       160;               % simulation time (s)

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;1;0;0;0]*0.01;          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
tau_eq        = [0;0;0];

%% Load plant

load("system_lin0.mat", "Alin", "Blin", "Clin");
Dlin = zeros(3,3);
plant = ss(Alin, Blin, Clin, Dlin);

%% T.F.

s=tf('s');

G_tf = Clin*inv(s*eye(size(Alin))-Alin)*Blin;

%% Frequency Response from model
figure(1)
bode(G_tf);

% There's a resonance peak

% Can see where CC poles are and their damping
figure(2)
pzmap(G_tf(1,1));
fb11 = bandwidth(G_tf(1,1))
figure(3)
pzmap(G_tf(1,2));
fb12 = bandwidth(G_tf(1,2))
figure(4)
pzmap(G_tf(1,3));
fb13 = bandwidth(G_tf(1,3))
figure(5)
pzmap(G_tf(2,1));
fb21 = bandwidth(G_tf(2,1))
figure(6)
pzmap(G_tf(2,2));
fb22 = bandwidth(G_tf(2,2))
figure(7)
pzmap(G_tf(2,3));
fb23 = bandwidth(G_tf(2,3))
figure(8)
pzmap(G_tf(3,1));
fb31 = bandwidth(G_tf(3,1))
figure(9)
pzmap(G_tf(3,2));
fb32 = bandwidth(G_tf(3,2))
figure(10)
pzmap(G_tf(3,3));
fb33 = bandwidth(G_tf(3,3))

% Idea for control if there's time: decoupler + 2nd order systems => 3
% independent real PIDs with Leva's rules

%%

w_freq = zeros(1000,1);
kk=1;
for i=1:1000
    w_freq(i,1)=kk;
    kk=kk+100;
end

%% Need Frequency Response in Simulink

% Per ora solo roll - ADATTARE ANCHE PITCH E YAW

open("fr_slk_001.slx")
sim("fr_slk_001.slx",Tend_slk)

data_fr = out.data_fr;
Freq_Resp = out.Freq_Resp;



