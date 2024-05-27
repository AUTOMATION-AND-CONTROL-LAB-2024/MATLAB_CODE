%% Main - Complementary Filter
clear all
close all
clc

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

%% RPY computation
acc_pole                = 8;                               % pole [Hz] of the high-pass-filter in input to the <RPY_computation> block
vel_pole                = 30;

%% Complementary Filter

Ts_meas = 0.01;
alpha = 0.95;

%% Y_EKF
% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
Ts_EKF_integr      = 0.001;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.01;       % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------
q_ps        = 100e-0;                    % q-elements related to yaw state
r_ps        = 600e+0;                    % variance related to psi computation from IMU measurement
x0_ps       = 0;                          % initial guess of psi angle
P0_ps       = 100;