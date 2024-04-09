%% DATA_ANALYSIS SCRIPT
clear all;
clc;
%% Inputs
labels = {'time','PWM1','PWM2','PWM3','PWM4','a_b_x','a_b_y','a_b_z','w_b_p','w_b_q','w_b_r','Roll_rate','Pitch_rate','Yaw_rate','mf_b_x','mf_b_y','mf_b_z','phi','theta','psi', 'phi_rate','theta_rate','psi_rate'};
filename = "Test_Wave_Acq_pitch_roll_1Hz" + ".mat";
raw_directory = 'RAW_DATA/';
raw_filename = raw_directory + filename;
window_size = 50; % used for the moving average

%% SAVE RAW ACQUISITION DATA
%saveAcqData(acquisition, labels, filename);

%% DATA CLEANING
cleanAndSaveData(raw_filename, labels, window_size);
%% DATA ANALYSIS
directory = 'CLEAN_DATA/';
filename = directory + filename;
data = load(filename);
data = data.filtered_data_table;
% data = data(14450:14800 , :);
% time = table2array(data(:,"time"));
% roll = table2array(data(:,"Roll_rate"));
% figure;
% plot(time,roll);
% hold on;
% grid on;
% offset = 49;
% omega = 11;
% plot(time, sin(omega*(time+offset)))
% zero_roll = findZeroIndices(roll);
% time_zero = getSubvectorByIndices(time,zero_roll);
%% PLOT



directory = "PLOTS";
plotData(data, labels, directory)
directory = "SUBPLOTS";
plotData(data, labels,directory)