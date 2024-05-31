%% Identification of the bias and variance of accelerometer, gyroscope and magnetometer of IMU
clear all
close all
clc
%% extraction of measurements from raw_data
raw_data = load("RAW_DATA/STATIC_SENSORS.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,columns] = size(dataset);

% delete the first zeros in the dataset
i=1;
while(dataset(i,2:columns) == zeros(1,columns-1))
i = i+1;    
end
dataset = dataset(i:rows,:);                    % remove the zeros from dataset
dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time

% find the other zeros in the dataset
for i = 1:1:size(dataset,1)
    if dataset(i,2:columns) == zeros(1,columns-1)
        break;
    end
end
dataset = dataset(1:i-1,:);

[rows,columns] = size(dataset);

%% signals division
time            = dataset(:,1);     
IMU_a_b         = dataset(:,6:8);       % (in dataset are the 6,7,8 columns)
IMU_w_b         = dataset(:,9:11);      % (in dataset are the 9,10,11 columns)
IMU_mf_b        = dataset(:,18:20);     % (in dataset are the 16,17,18 columns)

%% bias and variance of linear accelerations (a_b) 
IMU_a_b_mean = zeros(3,1);  % column vector
IMU_a_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_a_b_mean(i,1) = mean(IMU_a_b(:,i));
    IMU_a_b_var(i,1)  = var(IMU_a_b(:,i));
end

%% bias and viariance of angular velocity (w_b) 
IMU_w_b_mean = zeros(3,1);  % column vector
IMU_w_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_w_b_mean(i,1) = mean(IMU_w_b(:,i));
    IMU_w_b_var(i,1)  = var(IMU_w_b(:,i));
end

%% bias and variance of magnetic field (mf_b) 
IMU_mf_b_mean = zeros(3,1);  % column vector
IMU_mf_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_mf_b_mean(i,1) = mean(IMU_mf_b(:,i));
    IMU_mf_b_var(i,1)  = var(IMU_mf_b(:,i));
end

%% variance of RPY computation
IMU_RPY_meas = zeros(rows,3);          % IMU_RPY_meas(1,:) = phi(:), IMU_RPY_meas(2,:) = theta(:), IMU_RPY_meas(3,:) = psi(:)
IMU_RPY_var  = zeros(3,1);
for i = 1:1:rows
    IMU_RPY_meas(i,:) = RPY_computation(IMU_a_b(i,:)',IMU_mf_b(i,:)')';  % trigonometric RPY computation 
end
for i = 1:1:3
    IMU_RPY_var(i,1) = var(IMU_RPY_meas(:,i));
end

%% signals plot
signal = IMU_a_b;
% signal = IMU_w_b;
% signal = IMU_mf_b_mean;

figure(1)
subplot(3,1,1)
plot(time,signal(:,1)); 
grid on; title("x - component"); xlabel("time [s]");
subplot(3,1,2)
plot(time,signal(:,2));
grid on; title("y - component"); xlabel("time [s]");
subplot(3,1,3)
plot(time,signal(:,3));
grid on; title("z - component"); xlabel("time [s]");

%% save the data in a table structure
ColumnsName = {'IMU_a_b_var', 'IMU_w_b_mean', 'IMU_w_b_var', 'IMU_mf_b_var','IMU_RPY_var'};
IMU_var_bias = array2table([IMU_a_b_var, IMU_w_b_mean, IMU_w_b_var, IMU_mf_b_var,IMU_RPY_var],'VariableNames', ColumnsName);
disp(IMU_var_bias);
% save("IMUParameters","IMU_var_bias");