%% Identification of the bias and variance of accelerometer, gyroscope and magnetometer of IMU
clear all
close all
clc
%% extract static measurements from raw_data
raw_data = load("Test_Noise_Magnetometer_Acq_1.mat");
dataset = table2array(raw_data.Acq_Data);   %variable name "Acq_data"
[rows,colums] = size(dataset);
Ts = 0.01;  % sampling time of IMU

% delete the first zeros in the dataset
i=1;
while(dataset(i,2:colums) == zeros(1,colums-1))
i = i+1;    
end
dataset = dataset(i:rows,:);                     % remove the zeros from dataset
dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time

% find the other zeros in the dataset
for i = 1:1:size(dataset,1)
    if dataset(i,2:16) == zeros(1,15)
        break;
    end
end
dataset = dataset(1:i-1,:);

%% extract linear accelerations (a_b) (6,7,8 columns)
IMU_a_b = dataset(:,6:8);
IMU_a_b_mean = zeros(3,1);  % column vector
IMU_a_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_a_b_mean(i,1) = mean(IMU_a_b(:,i));
    IMU_a_b_var(i,1)  = var(IMU_a_b(:,i));
end
%% plot a_b
figure(1)
plot(dataset(:,1),IMU_a_b(:,1));    % time = dataset(:,1)
figure(2)
plot(dataset(:,1),IMU_a_b(:,2));
figure(3)
plot(dataset(:,1),IMU_a_b(:,3));

%% extract angular velocity (w_b) (9,10,11 columns)
IMU_w_b = dataset(:,9:11);
IMU_w_b_mean = zeros(3,1);  % column vector
IMU_w_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_w_b_mean(i,1) = mean(IMU_w_b(:,i));
    IMU_w_b_var(i,1)  = var(IMU_w_b(:,i));
end
%% plot w_b
figure(1)
plot(dataset(:,1),IMU_w_b(:,1));    % time = dataset(:,1)
figure(2)
plot(dataset(:,1),IMU_w_b(:,2));
figure(3)
plot(dataset(:,1),IMU_w_b(:,3));

%% extract magnetic field (mf_b) (16,17,18 columns)
IMU_mf_b = dataset(:,9:11);
IMU_mf_b_mean = zeros(3,1);  % column vector
IMU_mf_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_mf_b_mean(i,1) = mean(IMU_mf_b(:,i));
    IMU_mf_b_var(i,1)  = var(IMU_mf_b(:,i));
end
%% plot mf_b
figure(1)
plot(dataset(:,1),IMU_mf_b(:,1));    % time = dataset(:,1)
figure(2)
plot(dataset(:,1),IMU_mf_b(:,2));
figure(3)
plot(dataset(:,1),IMU_mf_b(:,3));

%% Table 
ColumnsName = {'IMU_a_b_var', 'IMU_w_b_mean', 'IMU_w_b_var', 'IMU_mf_b_var'};
IMU_var_bias = array2table([IMU_a_b_var, IMU_w_b_mean, IMU_w_b_var, IMU_mf_b_var],'VariableNames', ColumnsName);
disp(IMU_var_bias);
