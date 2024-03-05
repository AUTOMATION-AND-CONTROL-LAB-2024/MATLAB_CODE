clc;
close all;
%% ACQUISITION FILE
% ACQUIRE DATA FROM SIMULINK
colNames = {'time','PWM1','PWM2','PWM3','PWM4','Ax','Ay','Az','Wx','Wy','Wz','Roll_rate','Pitch_rate','Yaw_rate','PWM_M2','Thrust [N]'};
ciao = ones(16);
size(colNames)
data_array = ciao;
filename = 'RAW_DATA/ciao';
acq_Data = array2table(data_array,   'VariableNames',    colNames);
save(filename, "acq_Data");

