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

figure(1)
bode(G)
grid on

%% Controller

Kc = 0.04/Ixx;
tau_i = 10.74;
tau_d = 10.79;

PID = Kc * (tau_i*s+1) * (tau_d*s+1) / (tau_i*s) / (s+10);

PID_D = c2d(PID, Ts_slk);

