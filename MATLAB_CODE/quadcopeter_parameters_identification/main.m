%% Script - Quadcopeter Parameters Identification
clear all
close all
clc
%% Model parameters
getQuadcopterParameters();
Ts_slk = 0.01;
%% extraction of measurements from data
raw_data    = load("RAW_DATA/Test_system_controller_small_oscillation");
dataset     = table2array(raw_data.Acq_Data);

%% signals extraction
time    = dataset(:,1);          % time [s]
u1      = dataset(:,2)';         % pwm  [adim]
u2      = dataset(:,3)';         % pwm  [adim]
u3      = dataset(:,4)';         % pwm  [adim]
u4      = dataset(:,5)';         % pwm  [adim]
u       = [u1; u1; u3; u4];
yMeas   = dataset(:,15)';        % roll [rad]

%% plot 
figure(1)
plot(time, yMeas*180/pi);

%% 

A   = [+1;
       -1];
b   = [10;
       0;];
Aeq = []; beq = []; lb = []; ub = [];
x0  = 0.015;
x = fmincon(@(x)costFunction(x,u,yMeas,param,Ts_slk),x0,A,b,Aeq,beq,lb,ub);