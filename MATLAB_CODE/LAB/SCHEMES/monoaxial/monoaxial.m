clear all;
close all;
clc;

%% PARAMETERS
J = 0.1;
Ts = 0.01;

A = [Ts 0;Ts Ts];
B = [1;0];
C = [1,0];
D = 0;
