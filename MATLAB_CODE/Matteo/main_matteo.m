%% Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    % earth magnetic field (in inertia frame)
Ixx         =       4.856e-3;               %  moment of inertia
Iyy         =       4.856e-3;               %  moment of inertia (kg*m^2)
Izz         =       8.801e-3;               %  moment of inertia (kg*m^2)
l           =       0.225;
k           =       2.98e-7;
b           =       1.14e-7;
m           =       0.468;                  %  mass (kg)
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
x0          = [1;1;1;0;0;0]*(-pi/4+0.001);          % Initial State Vector - Roll, Pitch, Yaw angles and rates

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
IMU_var_bias_matrix = table2array(IMU_var_bias);      % need IMU_var_bias table
%%
IMU_a_b_bias          = ones(3,1)*0.1;                    % bias in IMU linear acceleration measurement     (THEORY)
IMU_w_b_bias          = IMU_var_bias_matrix(:,2);         % bias in IMU angular velocity measurement 
IMU_mf_b_bias         = ones(3,1)*0.1;                    % bias in IMU magnetic field measurement          (THEORY)
IMU_a_b_variance      = IMU_var_bias_matrix(:,1);         % variance in IMU linear acceleration measurement
IMU_w_b_variance      = IMU_var_bias_matrix(:,3);         % variance in IMU angular velocity measurement
IMU_mf_b_variance     = IMU_var_bias_matrix(:,4);         % variance in IMU magnetic field measurement 

%% EKF parameters

% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 2 * Ts_EKF_integr
Ts_EKF_integr      = 0.01;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.05;     % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------

q_angle     = 0.5;       % q-elements related to phi,theta,yaw states
q_bias_w_b  = 0.01;       % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q           = diag([q_angle,q_angle,q_angle, q_bias_w_b,q_bias_w_b,q_bias_w_b]);

r_ph_meas   = 0.1;    % variance related to phi computation from IMU measurement
r_th_meas   = 0.1;    % variance related to theta computation from IMU measurement
r_ps_meas   = 5;    % variance related to psi computation from IMU measurement
R           = diag([r_th_meas,r_th_meas,r_ps_meas]);

ph0         = -pi/4;                % initial guess of phi angle
th0         = -pi/4;                % initial guess of theta angle
ps0         = -pi/4;                % initial guess of psi angle
bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0EKF       = [ph0;th0;ps0;bias_wp0;bias_wq0;bias_wr0];

P0_ph_meas = r_ph_meas;
P0_th_meas = r_th_meas;
P0_ps_meas = r_ps_meas;
P0_bias_wp = IMU_w_b_variance(1,1);
P0_bias_wq = IMU_w_b_variance(2,1);
P0_bias_wr = IMU_w_b_variance(3,1);
P0         = diag([P0_ph_meas,P0_th_meas,P0_ps_meas,P0_bias_wp,P0_bias_wq,P0_bias_wr]);
