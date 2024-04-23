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

Ts_slk      =       0.1;              % sampling time (s)
Tend_slk    =       160;               % simulation time (s)

load("system_lin0.mat", "Alin", "Blin", "Clin");

plant=ss(Alin, Blin, Clin, zeros(3,3));

mpcobj = mpc(plant, Ts_slk);

mpcobj.PredictionHorizon=20; %10
mpcobj.ControlHorizon=2; %2

mpcobj.Weights.ManipulatedVariables=[0 0 0]; %0
mpcobj.Weights.ManipulatedVariablesRate=[0.1 0.1 0.1]; %0.1
mpcobj.Weights.OutputVariables=[1 1 1]; %1

