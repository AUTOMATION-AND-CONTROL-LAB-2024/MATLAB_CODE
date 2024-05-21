%% Identification of the bias and variance of accelerometer, gyroscope and magnetometer of IMU
clear all
close all
clc
%% extraction of measurements from raw_data
raw_data = load("RAW_DATA/STATIC_SENSORS.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,colums] = size(dataset);

% delete the first zeros in the dataset
i=1;
while(dataset(i,2:colums) == zeros(1,colums-1))
i = i+1;    
end
dataset = dataset(i:rows,:);                    % remove the zeros from dataset
dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time

% find the other zeros in the dataset
for i = 1:1:size(dataset,1)
    if dataset(i,2:colums) == zeros(1,colums-1)
        break;
    end
end
dataset = dataset(1:i-1,:);

[rows,colums] = size(dataset);


%% time extraction
time        = dataset(:,1);     
IMU_a_b     = dataset(:,6:8);       % (in dataset are the 6,7,8 columns)
IMU_w_b     = dataset(:,9:11);      % (in dataset are the 9,10,11 columns)
IMU_mf_b    = dataset(:,18:20);     % (in dataset are the 16,17,18 columns)

%% bias and dvariance in the linear accelerations (a_b) 
IMU_a_b_mean = zeros(3,1);  % column vector
IMU_a_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_a_b_mean(i,1) = mean(IMU_a_b(:,i));
    IMU_a_b_var(i,1)  = var(IMU_a_b(:,i));
end
%% plot a_b
figure(1)
plot(time,IMU_a_b(:,1));    
figure(2)
plot(time,IMU_a_b(:,2));
figure(3)
plot(time,IMU_a_b(:,3));

%% bias and viariance in the angular velocity (w_b) 
IMU_w_b_mean = zeros(3,1);  % column vector
IMU_w_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_w_b_mean(i,1) = mean(IMU_w_b(:,i));
    IMU_w_b_var(i,1)  = var(IMU_w_b(:,i));
end
%% plot w_b
figure(1)
plot(time,IMU_w_b(:,1));    
figure(2)
plot(time,IMU_w_b(:,2));
figure(3)
plot(time,IMU_w_b(:,3));

%% bias and variance in the magnetic field (mf_b) 
IMU_mf_b_mean = zeros(3,1);  % column vector
IMU_mf_b_var  = zeros(3,1);  % column vector
for i = 1:1:3
    IMU_mf_b_mean(i,1) = mean(IMU_mf_b(:,i));
    IMU_mf_b_var(i,1)  = var(IMU_mf_b(:,i));
end
%% plot mf_b
figure(1)
plot(time,IMU_mf_b(:,1));   
figure(2)
plot(time,IMU_mf_b(:,2));
figure(3)
plot(time,IMU_mf_b(:,3));

%% bias and variance in the RPY computation
IMU_RPY_meas = zeros(rows,3);          % IMU_RPY_meas(1,:) = phi(:), IMU_RPY_meas(2,:) = theta(:), IMU_RPY_meas(3,:) = psi(:)
IMU_RPY_var  = zeros(3,1);
for i = 1:1:rows
    IMU_RPY_meas(i,:) = RPY_computation(IMU_a_b(i,:)',IMU_mf_b(i,:)')';  % trigonometric RPY computation 
end
for i = 1:1:3
    IMU_RPY_var(i,1) = var(IMU_RPY_meas(:,i));
end

%% static noise analysis in the linear acceleration fo the IMU
Ts   = 0.01;            % sampling time of IMU
Fs   = 1/Ts;            % Sampling period       
L   = rows;             % Length of signal
time = (0:L-1)*Ts;      % Time vector
freq = Fs/L*(0:(L/2));

spectrum = zeros(ceil(L/2),3);
freq = freq(1:size(spectrum,1));
for i = 1:1:3
    signal = IMU_a_b(:,i);
    signal = lowpass(signal,Fs/2.01,Fs);
    signal = fft(signal);
    signal = abs(signal/L);
    signal = signal(1:ceil(L/2));
    signal(2:end-1) = 2*signal(2:end-1);
    spectrum(:,i) = signal;
end

plot(freq(2:end),spectrum(2:end,3),"LineWidth",2);  % a_b(1) -> spectrum(:,1)  a_b(2) -> spectrum(:,2)  a_b(3) -> spectrum(:,3)
title("Complex Magnitude of fft Spectrum");
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");
% good choice for the filter: cut-off freq = 20:30 Hz
%% save the data in a table structure
ColumnsName = {'IMU_a_b_var', 'IMU_w_b_mean', 'IMU_w_b_var', 'IMU_mf_b_var','IMU_RPY_var'};
IMU_var_bias = array2table([IMU_a_b_var, IMU_w_b_mean, IMU_w_b_var, IMU_mf_b_var,IMU_RPY_var],'VariableNames', ColumnsName);
disp(IMU_var_bias);
save("IMU","IMU_var_bias");