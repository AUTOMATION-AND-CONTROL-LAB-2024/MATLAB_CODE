%% Main
clear all
close all
clc

%% Model parameters 
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; 42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)
Ixx         =       0.015;                  %  moment of inertia (kg*m^2)
Iyy         =       0.015;                  %  moment of inertia (kg*m^2)
Izz         =       0.03;                   %  moment of inertia (kg*m^2)
l           =       0.25;                   %  quadcopter arm (m)
k           =       0.022;                  %  lift constant
b           =       1.14e-7;                %  drag constant
m           =       0.61+0.064*4;           %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k;b;m];
 
% cph         =       cos(phi);
% cth         =       cos(theta);
% cps         =       cos(psi);
% sph         =       sin(phi);
% sth         =       sin(theta);
% sps         =       sin(psi);

%% Simulation of the model with random parameters
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;1;1;0;0;0]*(0.5);    % Initial State Vector - Roll, Pitch, Yaw angles and rates

%% compute the inversion of matrix Mtau_u: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = Mtau_u * (u1,u2,u3,u4)'
syms k l b
Mtau_u = [k      k       k       k;
     0      0       l*k     -l*k;
     -l*k   l*k     0       0;
     -b     -b      b       b;];
inv(Mtau_u);

%% compute the inversion matrix of J
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

%% PolePlacement Control
load("K_pole_inv.mat");

%% IMU parameter loading
IMU_data = load("IMU.mat");
IMU_var_bias_matrix = table2array(IMU_data.IMU_var_bias);      % need IMU_var_bias table
clear IMU_data;

%% IMU parameters assignment
IMU_a_b_bias            = ones(3,1)*0.001;                  % bias in IMU linear acceleration measurement     (THEORY)
IMU_w_b_bias            = IMU_var_bias_matrix(:,2);         % bias in IMU angular velocity measurement 
IMU_mf_b_bias           = ones(3,1)*0.001;                  % bias in IMU magnetic field measurement          (THEORY)
IMU_a_b_variance        = IMU_var_bias_matrix(:,1);         % variance in IMU linear acceleration measurement
IMU_w_b_variance        = IMU_var_bias_matrix(:,3);         % variance in IMU angular velocity measurement
IMU_mf_b_variance       = ones(3,1)*0.001;                  % variance in IMU magnetic field measurement 

IMU_pole                = 10;
%% RPY computation
meas_pole               = 20;                               % pole [Hz] of the high-pass-filter of IMU_measurements block
RPY_pole                = 50;
%% rotation from IMU-frame to BODY-frame
angleZ = pi/4;
Rbody_frd = [cos(angleZ) -sin(angleZ)   0;
             sin(angleZ) cos(angleZ)    0;
             0              0           1;];
angleX = pi;
Rfrd_ned  = [1      0           0;
             0  cos(angleX) -sin(angleX);
             0  sin(angleX) cos(angleX);];
Rbody_ned = Rbody_frd*Rfrd_ned;
clear angleZ angleX Rfrd_ned;
%% EKF parameters

% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
Ts_EKF_integr      = 0.0001;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.01;     % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------

q_ph        = 8e-1;       % q-elements related to phi,theta,yaw states
q_th        = 8e-1;
q_ps        = 50e-0;
q_bias_w_b  = 1e-7;       % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q           = diag([q_ph,q_th,q_ps,q_bias_w_b,q_bias_w_b,q_bias_w_b]);

r_ph        = 1e-0;       % variance related to phi computation from IMU measurement
r_th        = 1e-0;       % variance related to theta computation from IMU measurement
r_ps        = 15e+1;      % variance related to psi computation from IMU measurement
R           = diag([r_th,r_th,r_ps]);

ph0         = 0;                    % initial guess of phi angle
th0         = 0;                    % initial guess of theta angle
ps0         = 0;                    % initial guess of psi angle
bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0EKF       = [ph0;th0;ps0;bias_wp0;bias_wq0;bias_wr0];

P0_ph       = 100;
P0_th       = 100;
P0_ps       = 100;
P0_bias_wp  = IMU_w_b_variance(1,1);
P0_bias_wq  = IMU_w_b_variance(2,1);
P0_bias_wr  = IMU_w_b_variance(3,1);
P0          = diag([P0_ph,P0_th,P0_ps,P0_bias_wp,P0_bias_wq,P0_bias_wr]);

%% EKF2 parameters

% % --------------------------------------------------------------------------------------------------------
% % oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
% Ts_EKF_integr      = 0.0001;     % [s] Ts for the ODE integration 
% Ts_EKF_meas        = 0.01;     % [s] Ts for measurement update
% % --------------------------------------------------------------------------------------------------------
% 
% % RP_EKF
% q_ph        = 630e-0;                 % q-elements related to phi states
% q_th        = 1300e-0;                 % q-elements related to theta states
% q_bias_w_b  = 1e-7;                 % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
% Q           = diag([q_ph,q_th,q_bias_w_b,q_bias_w_b,q_bias_w_b]);
% 
% r_ph        = 400e-0;                 % variance related to phi computation from IMU measurement
% r_th        = 900e-0;                 % variance related to theta computation from IMU measurement
% R           = diag([r_ph,r_th]);
% 
% ph0         = 0;                    % initial guess of phi angle
% th0         = 0;                    % initial guess of theta angle
% bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
% bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
% bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
% x0EKF       = [ph0;th0;bias_wp0;bias_wq0;bias_wr0];
% 
% P0_ph       = 100;
% P0_th       = 100;
% P0_bias_wp  = IMU_w_b_variance(1,1);
% P0_bias_wq  = IMU_w_b_variance(2,1);
% P0_bias_wr  = IMU_w_b_variance(3,1);
% P0          = diag([P0_ph,P0_th,P0_bias_wp,P0_bias_wq,P0_bias_wr]);
% 
% % Y_EKF
% q_ps        = 2000e-0;                  % q-elements related to yaw states
% r_ps        = 1500e+0;                  % variance related to psi computation from IMU measurement
% ps0         = 0;                        % initial guess of psi angle
% P0_ps       = 100;
% 
% % RPY_rate EKF
% q_ph_rate       = 900;       % q-elements related to phi,theta,yaw states
% q_th_rate       = 900;
% q_ps_rate       = 900;
% Q_rate          = diag([q_ph_rate,q_th_rate,q_ps_rate]);
% 
% r_ph_rate        = 40;       % variance related to phi computation from IMU measurement
% r_th_rate        = 40;       % variance related to theta computation from IMU measurement
% r_ps_rate        = 40;      % variance related to psi computation from IMU measurement
% R_rate           = diag([r_th_rate,r_th_rate,r_ps_rate]);
% 
% ph_rate0         = 0;        % initial guess of phi angle
% th_rate0         = 0;       % initial guess of theta angle
% ps_rate0         = 0;         % initial guess of psi angle
% x0_rate_EKF      = [ph_rate0;th_rate0;ps_rate0;];
% 
% P0_ph_rate       = 10;
% P0_th_rate       = 10;
% P0_ps_rate       = 10;
% P0_rate          = diag([P0_ph_rate,P0_th_rate,P0_ps_rate]);