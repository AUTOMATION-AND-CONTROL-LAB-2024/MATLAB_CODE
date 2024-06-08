%% noise analysis of IMU
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

%% select the signal and the component to plot (and then to analyze)
signal = IMU_a_b;       unitOfMeas = "accel. [m/s^2]";
% signal = IMU_w_b;     unitOfMeas = "vel. rad/s]";
% signal = IMU_mf_b;    unitOfMeas = "magn. field [gauss]";

figure()
sgtitle("selected signal");
subplot(3,1,1)
plot(time,signal(:,1)); 
grid on; title("x - component"); xlabel("time [s]");
subplot(3,1,2)
plot(time,signal(:,2));
grid on; title("y - component"); xlabel("time [s]");
subplot(3,1,3)
plot(time,signal(:,3));
grid on; title("z - component"); xlabel("time [s]");

%% frequency-domanin analysis: FFT of the signals
% (1) sampling settings
Ts = 0.01;                                          % sampling time of the measurements
Fs = 1/Ts;                                          % sampling frequency of measurements

%(2) FFT
magn     = cell(1,3);
freq     = cell(1,3);
for i = 1:1:3
% frequency analysis of the original signal
[magn{1,i},freq{1,i}] = magnitudeFFT(signal,Ts);
end

firstHarmonic = 5;                                  % to see the 0Hz-harmonic : 1 , to hide the 0Hz-component : >1

% (3) plot the results
figure()
sgtitle("FREQUENCY DOMAIN NOISE ANALYSIS (FFT)");
subplot(3,1,1);
plot(freq{1,1}(firstHarmonic:end),magn{1,1}(firstHarmonic:end),"LineWidth",1);
title(sprintf("Component X: magnitude of FFT spectrum"));
xlabel("f (Hz)");
ylabel("|Spectrum|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn{1,1}(firstHarmonic:end))]); % Set the y-axis limits

subplot(3,1,2);
plot(freq{1,2}(firstHarmonic:end),magn{1,2}(firstHarmonic:end),"LineWidth",1);
title(sprintf("Component Y: magnitude of FFT spectrum"));
xlabel("f (Hz)");
ylabel("|Spectrum|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn{1,2}(firstHarmonic:end))]); % Set the y-axis limits

subplot(3,1,3);
plot(freq{1,3}(firstHarmonic:end),magn{1,3}(firstHarmonic:end),"LineWidth",1);
title(sprintf("Component Z: magnitude of FFT spectrum"));
xlabel("f (Hz)");
ylabel("|Spectrum|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn{1,3}(firstHarmonic:end))]); % Set the y-axis limits