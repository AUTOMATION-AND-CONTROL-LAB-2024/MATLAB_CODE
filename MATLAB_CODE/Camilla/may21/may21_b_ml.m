clear all
close all
clc

%% Times

Ts_slk = 0.01;
Tend_slk = 400;

%% System TF

s = tf('s');

Ixx = 0.055;

G = 1/Ixx/s^2;

%% Study stuff
% 
% figure(1)
% bode(G)
% grid on

%% Controller

Kc = 0.04/Ixx; 

tau_i = 10.74;
tau_d = 10.79;

% tau_i = 10.74;
% tau_d = 5;


PID = Kc * (tau_i*s+1) * (tau_d*s+1) / (tau_i*s) / (s+30);

PID_D = c2d(PID, Ts_slk);

figure(2)
bode(G*PID)
grid on

Mastro_Filter = 1 / (s/20+1);

Mastro_Filter_D = c2d(Mastro_Filter, Ts_slk);

figure(3)
bode(G*PID*Mastro_Filter)
grid on

