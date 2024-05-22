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
Tinit   = 3275;
time    = dataset(Tinit:end,1) - dataset(Tinit,1);          % time [s]
u1      = dataset(Tinit:end,2)';         % pwm  [adim]
u2      = dataset(Tinit:end,3)';         % pwm  [adim]
u3      = dataset(Tinit:end,4)';         % pwm  [adim]
u4      = dataset(Tinit:end,5)';         % pwm  [adim]
yMeas   = dataset(Tinit:end,15)'+3.9*pi/180;        % roll [rad]

u1 = lowpass(u1,20,1/Ts_slk);
u2 = lowpass(u2,20,1/Ts_slk);
u3 = lowpass(u3,5,1/Ts_slk);
u4 = lowpass(u4,5,1/Ts_slk);
u       = [u1; u1; u3; u4] - 1000;
yMeas = lowpass(yMeas,20,1/Ts_slk);

%% plot 
figure(1)
plot(time, (yMeas)*180/pi );

figure(2)
plot(time, u3);
%% 

A   = [+1 0 0;
       -1 0 0;
       0  1 0;
       0 -1 0;];
b   = [3;
       0;
       -0.03;
       +0.07;];
Aeq = []; beq = []; lb = []; ub = [];
x0  = [0.015;-0.0544;1];
x = fmincon(@(x)costFunction(x,u,yMeas,param,Ts_slk),x0,A,b,Aeq,beq,lb,ub);

%%
[err,yHat] = costFunction(x,u,yMeas,param,Ts_slk);
figure(1)
plot(time, (yMeas)*180/pi );
hold on
plot(time, (yHat)*180/pi );