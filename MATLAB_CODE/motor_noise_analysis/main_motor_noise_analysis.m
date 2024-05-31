%% Identification of the noise in the IMU produced by the motors
clear all
close all
clc

%% extraction of measurements from raw_data
PWM = "100";                                % select the data to analyze PWM = "000" or "100" or ... "700"
raw_data = load("RAW_DATA/Test_MOTOR_NOISE_" + PWM + "PWM.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,columns] = size(dataset);

%% signals division   
time            = dataset(:,1);
IMU_Tend        = dataset(end,1);
IMU_a_b         = dataset(:,6:8);       % (in dataset are the 6,7,8 columns)
IMU_w_b         = dataset(:,9:11);      % (in dataset are the 9,10,11 columns)
IMU_mf_b        = dataset(:,18:20);     % (in dataset are the 16,17,18 columns)
phi             = dataset(:,21);
theta           = dataset(:,22);
psi             = dataset(:,23);

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

%% filtering
Ts_slk = 0.01;   
Tend = IMU_Tend;
filter_pole = 10;                                      % select the cut-off frequency of the filter

signalFiltered = zeros(length(signal(:,1)),1);
for i = 1:1:3
    % select the component to filter
    signalSim  = [time,signal(:,i)];

    % Create a simulation input object
    simIn = Simulink.SimulationInput("filter_test");

    % Set the start and stop times for the simulation
    simIn = setModelParameter(simIn, 'StartTime', num2str(0), 'StopTime', num2str(Tend));

    % Run the simulation
    out = sim(simIn);
    % save the data
    signalFiltered(:,i) = out.simout(:,1);
end

%% time-domain analysis: bias and variance 
% (1) bias and variance computation
signal_mean = zeros(3,1);  % column vector
signal_var  = zeros(3,1);  % column vector
for i = 1:1:3
    signal_mean(i,1) = mean(signal(:,i));
    signal_var(i,1)  = var(signal(:,i));
end

% (2) plot the results
for i = 1:1:3
    if i == 1
        component = "x";
    elseif i == 2
        component = "y";
    else
        component = "z";
    end
    figure()
    sgtitle("time-domain analysis");
    subplot(2,1,1)
    plot(time,signal(:,i)); 
    grid on; title(sprintf("%s - component : original signal",component));
    xlabel("time [s]"); ylabel(unitOfMeas);
    subplot(2,1,2)
    plot(time,signalFiltered(:,i));
    grid on; title(sprintf("%s - component : filtered signal at %d Hz",component,filter_pole)); 
    xlabel("time [s]"); ylabel(unitOfMeas);
end
%% frequency-domanin analysis: FFT of the signals
% (1) sampling settings
Ts = 0.01;                                          % sampling time of the measurements
Fs = 1/Ts;                                          % sampling frequency of measurements

%(2) FFT
magn_origin     = cell(1,3);
freq_origin     = cell(1,3);
magn_Nyquist    = cell(1,3);
freq_Nyquist    = cell(1,3);
magn_filtered   = cell(1,3);
freq_filtered   = cell(1,3);
for i = 1:1:3
% frequency analysis of the original signal
[magn_origin{1,i},freq_origin{1,i}] = magnitudeFFT(signal,Ts);

% frequency analysis of the signal filtered at the Nyquist frequency Fs/2
signal = lowpass(signal,0.99*Fs/2,Fs);              % remove high frequencies for aliasing
[magn_Nyquist{1,i},freq_Nyquist{1,i}] = magnitudeFFT(signal,Ts);

% frequency analysis of the signal filtered at <meas_pole> Hz
[magn_filtered{1,i},freq_filtered{1,i}] = magnitudeFFT(signalFiltered,Ts);
end

firstHarmonic = 1;                                  % to see the 0Hz-harmonic : 1 , to hide the 0Hz-component : >1

% (3) plot the results
for i = 1:1:3
    if i == 1
        component = "x";
    elseif i == 2
        component = "y";
    else
        component = "z";
    end
    figure()
    sgtitle("frequency-domain analysis");
    subplot(3,1,1);
    plot(freq_origin{1,i}(firstHarmonic:end),magn_origin{1,i}(firstHarmonic:end),"LineWidth",1);
    title(sprintf("component %s: Magnitude of fft Spectrum - original ",component));
    xlabel("f (Hz)");
    ylabel("|fft(spectrum)|");
    xlim([0 Fs/2]); % Set the x-axis limits
    ylim([0 max(magn_origin{1,i}(firstHarmonic:end))]); % Set the y-axis limits
    
    subplot(3,1,2);
    plot(freq_Nyquist{1,i}(firstHarmonic:end),magn_Nyquist{1,i}(firstHarmonic:end),"LineWidth",1);
    title(sprintf("component %s: Magnitude of fft Spectrum - filtered at %d Hz",component,Fs/2));
    xlabel("f (Hz)");
    ylabel("|fft(spectrum)|");
    xlim([0 Fs/2]); % Set the x-axis limits
    ylim([0 max(magn_origin{1,i}(firstHarmonic:end))]); % Set the y-axis limits
    
    subplot(3,1,3);
    plot(freq_filtered{1,i}(firstHarmonic:end),magn_filtered{1,i}(firstHarmonic:end),"LineWidth",1);
    title(sprintf("component %s: Magnitude of fft Spectrum - filtered at %d Hz",component,filter_pole));
    xlabel("f (Hz)");
    ylabel("|fft(spectrum)|");
    xlim([0 Fs/2]); % Set the x-axis limits
    ylim([0 max(magn_origin{1,i}(firstHarmonic:end))]); % Set the y-axis limits
end
