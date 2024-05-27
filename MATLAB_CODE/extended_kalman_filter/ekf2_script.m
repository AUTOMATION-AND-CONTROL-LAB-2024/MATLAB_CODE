%% Main - EKF 2.0
clear all
close all
clc

%%
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)

%% extraction of dataset from Test_RPY_quaternion
raw_data = load("RAW_DATA/Test_MOTOR_NOISE_000_700.mat");
dataset = table2array(raw_data.Acq_Data);   %variable name "Acq_data"
[rows,colums] = size(dataset);

% delete the first zeros in the dataset
% i=1;
% while(dataset(i,2:colums) == zeros(1,colums-1))
% i = i+1;    
% end
% dataset = dataset(i:rows,:);                     % remove the zeros from dataset
% dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time
% 
% % find the other zeros in the dataset
% for i = 1:1:size(dataset,1)
%     if dataset(i,2:colums) == zeros(1,colums-1)
%         break;
%     end
% end
% dataset = dataset(1:i-1,:);
% [rows,colums] = size(dataset);

% extraction of dataset
time            = dataset(:,1);
IMU_Tend        = dataset(end,1);  
IMU_a_b         = [time, dataset(:,6:8)];
IMU_w_b         = [time, dataset(:,9:11)];
IMU_mf_b        = [time, dataset(:,18:20)];
IMU_roll        = [time, dataset(:,15)];
IMU_pitch       = [time, dataset(:,16)];
IMU_yaw         = [time, dataset(:,17)];
IMU_roll_rate   = [time, dataset(:,12)];
IMU_pitch_rate  = [time, dataset(:,13)];
IMU_yaw_rate    = [time, dataset(:,14)];  

%% Simulation
Ts_slk      =       0.01;           % sampling time (s)
Tend_slk    =       IMU_Tend;       % simulation time (s)

%% IMU parameter loading
IMU_data = load("IMUParameters.mat");
IMU_var_bias_matrix = table2array(IMU_data.IMU_var_bias);      % need IMU_var_bias table
clear IMU_data;

%% IMU parameters assignment
IMU_a_b_bias            = ones(3,1)*0.001;                  % bias in IMU linear acceleration measurement     (THEORY)
IMU_w_b_bias            = IMU_var_bias_matrix(:,2);         % bias in IMU angular velocity measurement 
IMU_mf_b_bias           = ones(3,1)*0.001;                  % bias in IMU magnetic field measurement          (THEORY)
IMU_a_b_variance        = IMU_var_bias_matrix(:,1);         % variance in IMU linear acceleration measurement
IMU_w_b_variance        = IMU_var_bias_matrix(:,3);         % variance in IMU angular velocity measurement
IMU_mf_b_variance       = ones(3,1)*0.001;                  % variance in IMU magnetic field measurement 

%% RPY computation
acc_pole                = 2;                               % pole [Hz] of the high-pass-filter in input to the <RPY_computation> block
vel_pole                = 20;
%% EKF2 parameters

% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
Ts_EKF_integr      = 0.001;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.01;       % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------

% RP_EKF
q_ph        = 200e-0;                 % q-elements related to phi states
q_th        = 200e-0;                 % q-elements related to theta states
q_bias_w_b  = 1e-3;                 % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q_phth      = diag([q_ph,q_th,q_bias_w_b,q_bias_w_b,q_bias_w_b]);

r_ph        = 800e-0;                 % variance related to phi computation from IMU measurement
r_th        = 800e-0;                 % variance related to theta computation from IMU measurement
R_phth      = diag([r_ph,r_th]);

ph0         = 0;                    % initial guess of phi angle
th0         = 0;                    % initial guess of theta angle
bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0_phth     = [ph0;th0;bias_wp0;bias_wq0;bias_wr0];

P0_ph       = 200;
P0_th       = 800;
P0_bias_wp  = IMU_w_b_variance(1,1);
P0_bias_wq  = IMU_w_b_variance(2,1);
P0_bias_wr  = IMU_w_b_variance(3,1);
P0_phth     = diag([P0_ph,P0_th,P0_bias_wp,P0_bias_wq,P0_bias_wr]);

% Y_EKF
q_ps        = 100e-0;                    % q-elements related to yaw state
r_ps        = 600e+0;                    % variance related to psi computation from IMU measurement
x0_ps       = 0;                          % initial guess of psi angle
P0_ps       = 100;

% RPY_rate EKF
q_ph_rate       = 900;                    % q-elements related to phi_rate,theta,yaw
q_th_rate       = 900;                    % q-elements related to theta_rate
q_ps_rate       = 900;                    % q-elements related to yaw_rate
Q_rate          = diag([q_ph_rate,q_th_rate,q_ps_rate]);

r_ph_rate        = 40;                    % variance related to phi computation from IMU measurement
r_th_rate        = 40;                    % variance related to theta computation from IMU measurement
r_ps_rate        = 40;                    % variance related to psi computation from IMU measurement
R_rate           = diag([r_th_rate,r_th_rate,r_ps_rate]);

ph_rate0         = IMU_roll(1,2);         % initial guess of phi angle
th_rate0         = IMU_pitch(1,2);        % initial guess of theta angle
ps_rate0         = IMU_yaw(1,2);          % initial guess of psi angle
x0_rate_EKF      = [ph_rate0;th_rate0;ps_rate0;];

P0_ph_rate       = 10;
P0_th_rate       = 10;
P0_ps_rate       = 10;
P0_rate          = diag([P0_ph_rate,P0_th_rate,P0_ps_rate]);

%% Error computation
phi_estim       = out.simout(:,1);
theta_estim     = out.simout(:,2);
psi_estim       = out.simout(:,3);

N               = length(phi_estim);
phi_error       = sqrt((IMU_roll(:,2) - phi_estim)'*(IMU_roll(:,2) - phi_estim)/N);
theta_error     = sqrt((IMU_pitch(:,2) - theta_estim)'*(IMU_pitch(:,2) - theta_estim)/N);
psi_error       = sqrt((IMU_yaw(:,2) - psi_estim)'*(IMU_yaw(:,2) - psi_estim)/N);

fprintf('roll error:  %.2f \n',phi_error);
fprintf('pitch error: %.2f \n',theta_error);
fprintf('yaw error:   %.2f \n',psi_error);
fprintf('----------------------------------------- \n');



