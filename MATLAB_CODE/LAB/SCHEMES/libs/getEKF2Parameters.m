function [] = getEKF2Parameters()
%% IMU parameters loading
IMU_data = load("IMU.mat");
IMU_var_bias_matrix = table2array(IMU_data.IMU_var_bias);      % need IMU_var_bias table
clear IMU_data;

% IMU parameters assignment
IMU_a_b_bias            = ones(3,1)*0.001;                  % bias in IMU linear acceleration measurement     (THEORETICAL)
IMU_w_b_bias            = IMU_var_bias_matrix(:,2);         % bias in IMU angular velocity measurement 
IMU_mf_b_bias           = ones(3,1)*0.001;                  % bias in IMU magnetic field measurement          (THEORETICAL)
IMU_a_b_variance        = IMU_var_bias_matrix(:,1);         % variance in IMU linear acceleration measurement
IMU_w_b_variance        = IMU_var_bias_matrix(:,3);         % variance in IMU angular velocity measurement
IMU_mf_b_variance       = ones(3,1)*0.001;                  % variance in IMU magnetic field measurement

%% RPY computation
meas_pole                = 15;                               % pole [Hz] of the high-pass-filter of IMU_measurements block

%% EKF2 parameters
% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
Ts_EKF_integr      = 0.001;   % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.01;     % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------

% RP_EKF
q_ph        = 100e-0;                 % q-elements related to phi states
q_th        = 100e-0;                 % q-elements related to theta states
q_bias_w_b  = 1e-3;                 % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q_phth      = diag([q_ph,q_th,q_bias_w_b,q_bias_w_b,q_bias_w_b]);

r_ph        = 400e-0;                 % variance related to phi computation from IMU measurement
r_th        = 400e-0;                 % variance related to theta computation from IMU measurement
R_phth      = diag([r_ph,r_th]);

ph0         = 0;                    % initial guess of phi angle
th0         = 0;                    % initial guess of theta angle
bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0_phth     = [ph0;th0;bias_wp0;bias_wq0;bias_wr0];

P0_ph       = 100;
P0_th       = 400;
P0_bias_wp  = IMU_w_b_variance(1,1);
P0_bias_wq  = IMU_w_b_variance(2,1);
P0_bias_wr  = IMU_w_b_variance(3,1);
P0_phth     = diag([P0_ph,P0_th,P0_bias_wp,P0_bias_wq,P0_bias_wr]);

% Y_EKF
q_ps        = 170e-0;                    % q-elements related to yaw state
r_ps        = 200e+0;                    % variance related to psi computation from IMU measurement
x0_ps       = 0;                          % initial guess of psi angle
P0_ps       = 100;

%% To Workspace
assignin('base', 'meas_pole', meas_pole);
assignin('base', 'Ts_EKF_integr', Ts_EKF_integr);
assignin('base', 'Ts_EKF_meas', Ts_EKF_meas);
assignin('base', 'Q_phth', Q_phth);
assignin('base', 'R_phth', R_phth);
assignin('base', 'x0_phth', x0_phth);
assignin('base', 'P0_phth', P0_phth);
assignin('base', 'IMU_w_b_bias', IMU_w_b_bias);
assignin('base', 'q_ps', q_ps);
assignin('base', 'r_ps', r_ps);
assignin('base', 'x0_ps', x0_ps);
assignin('base', 'P0_ps', P0_ps);
end