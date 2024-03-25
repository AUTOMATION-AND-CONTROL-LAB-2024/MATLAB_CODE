%% MONOAXIAL MODEL OF THE QUADCOPTER
close all;
clear all;
clc;

%% PARAMETERS
J = 0.1;
Ts = 0.01;

A = [Ts 0;Ts, Ts];
B = [1;0];
C = [1,0];
D = 0;

sys = ss(A,B,C,D);
G = tf(sys);  
%% SYSTEM
% sys=ss(A,B,C,D)                  % continuous system
% G = tf(sys)                            % sampling time
% sys_z =c2d(sys,Ts,'tustin')   % discrete system
% pCont=[11 10];                    % poles in s-domain
% pDisc=exp(pCont.*Ts);         % poles in z-domain
% K_cont=place(A,B,pCont);
% K = place(sys_z.A,sys_z.B,pDisc)