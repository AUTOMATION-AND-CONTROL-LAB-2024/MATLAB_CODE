%% Split the data regarding the noise in the IMU produced by the motors
clear all
close all
clc

%% extraction of measurements from raw_data
raw_data = load("RAW_DATA/Test_MOTOR_NOISE_000_700.mat");
dataset = table2array(raw_data.Acq_Data);   % variable name "Acq_data"
[rows,colums] = size(dataset);

%% signals extraction   
time            = dataset(:,1);
samples         = 1:1:length(time);
IMU_Tend        = dataset(end,1);
IMU_a_b         = dataset(:,6:8);
IMU_w_b         = dataset(:,9:11);
IMU_mf_b        = dataset(:,18:20);

%% plot a_b
figure(1)
plot(samples,IMU_a_b(:,1));    
figure(2)
plot(time,IMU_a_b(:,2));
figure(3)
plot(samples,IMU_a_b(:,3));

%% define the time intervals
ni000   = 41928;
nf000   = 50074; % ok
ni100   = 54289; 
nf100   = 59641; % ok
ni200   = 68400;
nf200   = 78178; % ok
ni300   = 83186;
nf300   = 89793; % ok

ni500   = 5213;
nf500   = 9215; % ok

ni600   = 181618;
nf600   = 189688; % ok
ni700   = 195094;
nf700   = 200870; % ok

%% create the file with the selected time interval
ni = ni700;
nf = nf700;
PWM = "700";

datasetSection       = dataset(ni:nf,:);                             % select the time interval
datasetSection(:,1)  = datasetSection(:,1) - datasetSection(1,1);    % shift the time time = datasetSection(:,1)

colNames = {'time','PWM1','PWM2','PWM3','PWM4','a_b_x','a_b_y','a_b_z','w_b_p','w_b_q','w_b_r','Roll_rate','Pitch_rate','Yaw_rate','Roll','Pitch','Yaw','mf_b_x','mf_b_y','mf_b_z','phi','theta','psi', 'phi_rate','theta_rate','psi_rate'};
Acq_Data = array2table(datasetSection,'VariableNames',colNames);
filename = "RAW_DATA/Test_"+"MOTOR_NOISE_" + PWM +"PWM";
save(filename, "Acq_Data")

% check the result

raw_data2 = load("RAW_DATA/Test_MOTOR_NOISE_" + PWM +"PWM.mat");
dataset2 = table2array(raw_data2.Acq_Data);   % variable name "Acq_data"
time2               = dataset2(:,1);
IMU_a_b2            = zeros(rows,3);
IMU_a_b2(ni:nf,:)   = dataset2(:,6:8);
samples2            = 1:1:length(time2);

figure(1)
plot(time,IMU_a_b(:,3));    
hold on
plot(time,IMU_a_b2(:,3));
