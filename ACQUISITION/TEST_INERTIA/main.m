%% DATA_ANALYSIS SCRIPT
%% Inputs
labels = {'time','PWM1','PWM2','PWM3','PWM4','Ax','Ay','Az','Wx','Wy','Wz','Roll_rate','Pitch_rate','Yaw_rate','PWM_M2','Thrust [N]'};
filename = "ciao" + ".mat";
raw_directory = 'RAW_DATA/';
raw_filename = raw_directory + filename;
window_size = 50; % used for the moving average
acquisition = Acq_Data;

%% SAVE RAW ACQUISITION DATA
saveAcqData(acquisition, labels, filename);

%% DATA CLEANING
cleanAndSaveData(raw_filename, labels, window_size);

%% PLOT