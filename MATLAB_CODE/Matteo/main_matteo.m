%% Plant Model Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;               %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;]; %  earth magnetic field (in inertia frame)
Ixx         =       4.856e-3;           %  moment of inertia
Iyy         =       4.856e-3;           %  moment of inertia (kg*m^2)
Izz         =       8.801e-3;           %  moment of inertia (kg*m^2)
l           =       0.225;
k           =       2.98e-7;
b           =       1.14e-7;
m           =       0.468;              %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];
 
% cph         =       cos(phi);
% cth         =       cos(theta);
% cps         =       cos(psi);
% sph         =       sin(phi);
% sth         =       sin(theta);
% sps         =       sin(psi);

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       10;                % final time (s) 

%% Initial conditions (which correspond to the equilibrium conditions)
x_eq          = [1;1;2;0;0;0]*(-pi/2+0.001);          % State Equilibrium Vector - Roll, Pitch, Yaw angles and rates
% tau_m_eq      = [1;1;1;1];              % Input Equilibrium - Motor Torque
w_eq          = [1000;1200;1400;2000];  % Control Input Equilibrium - Propellers' Angular Velocities

%% compute the inversion of matrix Mu: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = Mu * (u1,u2,u3,u4)'
syms k l b
A = [k      k       k       k;
     0      0       l*k     -l*k;
     -l*k   l*k     0       0;
     -b     -b      b       b;];
inv(A)

%% compute the inversion matric of J
syms J11 J12 J13 J21 J22 J23 J31 J32 J33
syms C11 C12 C13 C21 C22 C23 C31 C32 C33
J = [J11 J12 J13;
     J21 J22 J23;
     J31 J32 J33;];
C = [C11 C12 C13;
     C21 C22 C23;
     C31 C32 C33;];
invJ = inv(J);

%% Linearized Model (Inverse Dynamic)
A = [zeros(3,3),    eye(3);
     zeros(3,3),    zeros(3,3);];
B = [zeros(3,3);
     eye(3);];
Mo = ctrb(A,B);
rankMo = rank(Mo);  % ok, it is controllable
system_poles = eig(A);
poles = -[0.1,0.12,0.13,0.14,0.15,0.16];
[Kpole ,prec]= place(A,B,poles);

%% IMU parameters
a_bias          = 0.1;  % bias in IMU linear acceleration measurement
a_variance      = 0.1;  % variance in IMU linear acceleration measurement
w_bias          = 0.1;  % bias in IMU angular velocity measurement
w_variance      = 0.1;  % variance in IMU angular velocity measurement
mf_bias         = 0.1;  % bias in IMU magnetic field measurement
mf_variance     = 0.1;  % variance in IMU magnetic field measurement 

%% EKF parameters
Ts_EKF_integr      = 0.01;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.05;     % [s] Ts for measurement update

q_angle     = 1;        % q-elements related to phi,theta,yaw states
q_bias_w    = 1;        % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q           = diag([q_angle,q_angle,q_angle, q_bias_w,q_bias_w,q_bias_w]);

r_ph_meas   = 0.1;    % variance related to phi computation from IMU measurement
r_th_meas   = 0.1;    % variance related to theta computation from IMU measurement
r_ps_meas   = 0.1;    % variance related to psi computation from IMU measurement
R           = diag([r_th_meas,r_th_meas,r_ps_meas]);

ph0         = 0;    % initial guess of phi angle
th0         = 0;    % initial guess of theta angle
ps0         = 0;    % initial guess of psi angle
bias_wp     = 0.1;  % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq     = 0.1;  % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr     = 0.1;  % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0          = [ph0;th0;ps0;bias_wp;bias_wq;bias_wr];

P0          = 0.1*eye(6);
