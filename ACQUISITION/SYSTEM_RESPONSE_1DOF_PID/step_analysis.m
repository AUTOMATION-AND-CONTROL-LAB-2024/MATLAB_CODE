%% CLOSED LOOP STEP ANALYSIS
clc;
clear all;
close all;

%% Data parsing
load('Test_PID_1dof.mat');
t          = Acq_Data.time(5500:7000)-Acq_Data.time(5500);
y_ref    = Acq_Data.roll_ref(5500:7000);
y_meas =  Acq_Data.Roll(5500:7000)+3.9*pi/180;
data.time = t;
data.signals.values = [y_ref, y_meas];
% plot(t,y_ref)%,t);
% grid("on")
% hold("on")
% plot(t,y_meas)
%% SYSTEM PARAMETERS
Ixx         =   0.45;                  %  moment of inertia (kg*m^2)
Ts_slk      =   0.001;
s           =   tf('s');
Gs = Ixx/s^2;
Gz = c2d(Gs,Ts_slk);
[num den] = tfdata(Gz, 'v');
ind = find(y_ref, 1);
t_step = t(ind);

%% PID PARAMETERS
Kc = 1e-0*Ixx;
tau_i = 0.5;    
tau_d = 0.5;    

% 0.8 con gain 20
% 0.4 con gain 45
% 0.5 con gain 35 molto good
% 0.2 con gain -

PID = Kc * (tau_i*s+1) * (tau_d*s+1) / (s) / (1+s/130);
filter = 1/(1+s/120);
PID_D = c2d(PID, Ts_slk);
filter_d = c2d(filter, Ts_slk);
PID_ss      =   ss(PID_D);
A           =   PID_ss.A;
B           =   PID_ss.B;
C           =   PID_ss.C;
D           =   PID_ss.D;

A_cond      =   A-B*inv(D)*C;
B_cond      =   B*inv(D);

