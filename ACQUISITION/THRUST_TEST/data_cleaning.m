clear all;
close all;
clc;

% DATA CLEANING
filename = "RAW_DATA/Test_Thrust_M2_2N.mat";
raw_acq = load(filename);
dataset = raw_acq.Acq_Data;
dataset = table2array(dataset);
nonzero_indices = find(dataset(:,2) ~= 0);
first_idx = nonzero_indices(1);
last_idx  = nonzero_indices(size(nonzero_indices));
effective_dataset = dataset(first_idx:last_idx,:);
time_offset = effective_dataset(1,1);
time_offset_array   = time_offset * ones(size(effective_dataset,1),1);
effective_dataset(:,1) = effective_dataset(:,1) - time_offset_array;
time_column = effective_dataset(:,1);
fields = fieldnames(raw_acq.Acq_Data);
window_size = 50;
for i = 1:size(effective_dataset, 2)
   filtered_data(:,i) = movmean(effective_dataset(:,i),window_size);
end
colNames = {'time','PWM1','PWM2','PWM3','PWM4','Ax','Ay','Az','Wx','Wy','Wz','Roll_rate','Pitch_rate','Yaw_rate','PWM_M2','Thrust [N]'};
filtered_data(:, 1) = time_column;
filtered_data = array2table(filtered_data,   'VariableNames',    colNames);
filename = erase(filename, "RAW_DATA/");
filename = "CLEAN_DATA/"+filename;
save(filename, "filtered_data");
