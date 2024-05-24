%% Identification of the noise in the IMU produced by the motors
clear all
close all
clc

%% extraction of measurements from raw_data
PWM = "600";                                % select the data to analyze PWM = "000" or "100" or ... "700"
raw_data = load("RAW_DATA/Test_MOTOR_NOISE_" + PWM + "PWM.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,colums] = size(dataset);

%% signals division   
time            = dataset(:,1);
IMU_Tend        = dataset(end,1);
IMU_a_b         = dataset(:,6:8);       % (in dataset are the 6,7,8 columns)
IMU_w_b         = dataset(:,9:11);      % (in dataset are the 9,10,11 columns)
IMU_mf_b        = dataset(:,18:20);     % (in dataset are the 16,17,18 columns)
phi             = dataset(:,21);
theta           = dataset(:,22);
psi             = dataset(:,23);

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

%% plot signals
% signal = IMU_a_b;
signal = IMU_a_b;
% signal = IMU_mf_b;

% figure(1)
% plot(time,signal(:,1));    
% figure(2)
% plot(time,signal(:,2));
figure(3)
plot(time,signal(:,3));

%% motor noise analysis
Ts = 0.01;                                          % sampling time of the measurements
Fs = 1/Ts;                                          % sampling frequency of the measurements
component = 2;                                      % 1 -> x-component  2 -> y-component    3 -> z-component
signal = signal(:,component);
% signal = IMU_w_b(:,component);
% signal = IMU_mf_b(:,component);

%% simulation
Ts_slk = 0.01;   
Tend = IMU_Tend;

meas_pole = 10;                                      % select the cut-off frequency of the filter
signalSim  = [time,signal];

% Create a simulation input object
simIn = Simulink.SimulationInput("filter_test");

% Set the start and stop times for the simulation
simIn = setModelParameter(simIn, 'StartTime', num2str(0), 'StopTime', num2str(Tend));

% Run the simulation
out = sim(simIn);
signalFiltered = out.simout;

%% comparison
% frequency analysis of the original signal
[magn_origin,freq_origin] = signalFFT(signal,Ts);

% frequency analysis of the signal filtered at the Nyquist frequency Fs/2
signal = lowpass(signal,0.99*Fs/2,Fs);              % remove high frequencies for aliasing
[magn_filteredNyquist,freq_filteredNyquist] = signalFFT(signal,Ts);

% frequency analysis of the signal filtered at <meas_pole> Hz
[magn_filtered,freq_filtered] = signalFFT(signalFiltered,Ts);

firstHarmonic = 1;                                  % to see the 0Hz-harmonic : 1 , to hide the 0Hz-component : >1

figure(5)

subplot(3,1,1);
plot(freq_origin(firstHarmonic:end),magn_origin(firstHarmonic:end),"LineWidth",1);
title("Magnitude of fft Spectrum - original");
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn_origin)]); % Set the y-axis limits

subplot(3,1,2);
plot(freq_filteredNyquist(firstHarmonic:end),magn_filteredNyquist(firstHarmonic:end),"LineWidth",1);
title(sprintf("Magnitude of fft Spectrum - filtered at %d Hz",Fs/2));
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn_origin)]); % Set the y-axis limits

subplot(3,1,3);
plot(freq_filtered(2:end),magn_filtered(2:end),"LineWidth",1);
title(sprintf("Complex Magnitude of fft Spectrum - filtered at %d Hz",meas_pole));
xlabel("f (Hz)");
ylabel("|fft(spectrum)|");
xlim([0 Fs/2]); % Set the x-axis limits
ylim([0 max(magn_origin)]); % Set the y-axis limits
