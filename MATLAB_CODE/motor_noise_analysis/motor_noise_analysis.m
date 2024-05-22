%% Identification of the noise in the IMU produced by the motors
clear all
close all
clc
%% extraction of measurements from raw_data
raw_data = load("RAW_DATA/Test_MOTOR_NOISE_100_700.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,colums] = size(dataset);

% delete the first zeros in the dataset
% i=1;
% while(dataset(i,2:colums) == zeros(1,colums-1))
% i = i+1;    
% end
% dataset = dataset(i:rows,:);                    % remove the zeros from dataset
% dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time
% 
% % find the other zeros in the dataset
% for i = 1:1:size(dataset,1)
%     if dataset(i,2:colums) == zeros(1,colums-1)
%         break;
%     end
% end
% dataset = dataset(1:i-1,:);

[rows,colums] = size(dataset);

%% signals extraction   
time            = dataset(:,1);
IMU_Tend        = dataset(end,1);
IMU_a_b         = dataset(:,6:8);
IMU_w_b         = dataset(:,9:11);
IMU_mf_b        = dataset(:,18:20);
phi             = dataset(:,21);
theta           = dataset(:,22);
psi             = dataset(:,23);

%% extract linear accelerations (a_b) (6,7,8 columns)
% IMU_a_b_mean = zeros(3,1);  % column vector
% IMU_a_b_var  = zeros(3,1);  % column vector
% for i = 1:1:3
%     IMU_a_b_mean(i,1) = mean(IMU_a_b(i));
%     IMU_a_b_var(i,1)  = var(IMU_a_b(i));
% end
%% plot a_b
figure(1)
plot(time,IMU_a_b(:,1));    
figure(2)
plot(time,IMU_a_b(:,2));
figure(3)
plot(time,IMU_a_b(:,3));

%% extract angular velocity (w_b) (9,10,11 columns)
% IMU_w_b_mean = zeros(3,1);  % column vector
% IMU_w_b_var  = zeros(3,1);  % column vector
% for i = 1:1:3
%     IMU_w_b_mean(i,1) = mean(IMU_w_b(i));
%     IMU_w_b_var(i,1)  = var(IMU_w_b(i));
% end
%% plot w_b
figure(1)
plot(time,IMU_w_b(:,1));    
figure(2)
plot(time,IMU_w_b(:,2));
figure(3)
plot(time,IMU_w_b(:,3));

%% extract magnetic field (mf_b) (16,17,18 columns)
IMU_mf_b_mean = zeros(3,1);  % column vector
% IMU_mf_b_var  = zeros(3,1);  % column vector
% for i = 1:1:3
%     IMU_mf_b_mean(i,1) = mean(IMU_mf_b(:,i));
%     IMU_mf_b_var(i,1)  = var(IMU_mf_b(:,i));
% end
%% plot mf_b
figure(1)
plot(time,IMU_mf_b(:,1));   
figure(2)
plot(time,IMU_mf_b(:,2));
figure(3)
plot(time,IMU_mf_b(:,3));

%% plot RPY estimated by EKF
figure(1)
plot(time,phi);    
figure(2)
plot(time,theta);
figure(3)
plot(time,psi);

%% DIVISION NOISE VS NO_NOISE
% nDivision = 3526;
% IMU_a_b_noNoise = IMU_a_b(1:nDivision,:);
% IMU_w_b_noNoise = IMU_w_b(1:nDivision,:);
% IMU_mf_b_noNoise = IMU_mf_b(1:nDivision,:);
%
% time_noise   = time(nDivision+1:end,:) - time(nDivision+1,1);
% IMU_a_b_noise = IMU_a_b(nDivision+1:end,:);
% IMU_w_b_noise = IMU_w_b(nDivision+1:end,:);
% IMU_mf_b_noise = IMU_mf_b(nDivision+1:end,:);

indexInit = find(time == 433);
indexFinal = find(time == 514);
time_noNoise        = time(indexInit:indexFinal,:) - time(indexInit,1);
IMU_a_b_noNoise     = IMU_a_b(indexInit:indexFinal,:);
IMU_w_b_noNoise     = IMU_w_b(indexInit:indexFinal,:);
IMU_mf_b_noNoise    = IMU_mf_b(indexInit:indexFinal,:);

indexInit = find(time == 556);
indexFinal = find(time == 610);
time_noise         = time(indexInit:indexFinal,:) - time(indexInit,1);
IMU_a_b_noise      = IMU_a_b(indexInit:indexFinal,:);
IMU_w_b_noise      = IMU_w_b(indexInit:indexFinal,:);
IMU_mf_b_noise     = IMU_mf_b(indexInit:indexFinal,:);

indexInit = find(time == 1963);
indexFinal = find(time == 2023);
time_noise700         = time(indexInit:indexFinal,:) - time(indexInit,1);
IMU_a_b_noise700      = IMU_a_b(indexInit:indexFinal,:);
IMU_w_b_noise700      = IMU_w_b(indexInit:indexFinal,:);
IMU_mf_b_noise700     = IMU_mf_b(indexInit:indexFinal,:);
%%
figure(4)
plot(time_noise700,IMU_a_b_noise700(:,3));
%% MOTOR NOISE analysis
Ts = 0.01;

[magn_noNoise,freq_noNoise] = signalFFT(IMU_w_b_noNoise(:,3),Ts);
figure(5)
plot(freq_noNoise(1:end),magn_noNoise(1:end),"LineWidth",1);  % a_b(1) -> spectrum(:,1)  a_b(2) -> spectrum(:,2)  a_b(3) -> spectrum(:,3)
title("Magnitude of fft Spectrum (no noise)");
xlabel("f (Hz)");
ylabel("|fft(spectrum)| no noise");

[magn_noise,freq_noise] = signalFFT(IMU_w_b_noise(:,3),Ts);
figure(6)
plot(freq_noise(1:end),magn_noise(1:end),"LineWidth",1);  % a_b(1) -> spectrum(:,1)  a_b(2) -> spectrum(:,2)  a_b(3) -> spectrum(:,3)
title("Magnitude of fft Spectrum (noise)");
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");

[magn_noise700,freq_noise700] = signalFFT(IMU_w_b_noise700(:,3),Ts);
figure(7)
plot(freq_noise700(1:end),magn_noise700(1:end),"LineWidth",1);  % a_b(1) -> spectrum(:,1)  a_b(2) -> spectrum(:,2)  a_b(3) -> spectrum(:,3)
title("Magnitude of fft Spectrum (noise 700)");
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");
%% for simulink
Ts_slk = 0.01;
meas_pole = 8;
signal_sim  = [time_noise700,IMU_a_b_noise700];
Tend = time_noise700(end);
%%
filtered = out.simout(:,1);
%%
% filtered = lowpass(IMU_w_b_noise(:,2),20,Fs);
[magn_filtered,freq_filtered] = signalFFT(filtered,Ts);
figure(8)
n = find(freq_filtered == 0.0034)
plot(freq_filtered(2:end),magn_filtered(2:end),"LineWidth",1);  % a_b(1) -> spectrum(:,1)  a_b(2) -> spectrum(:,2)  a_b(3) -> spectrum(:,3)
title("Complex Magnitude of fft Spectrum (filtered)");
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");

