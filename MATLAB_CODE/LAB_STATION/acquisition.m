%% ACQUISITION FILE

colNames = {'time','PWM1','PWM2','PWM3','PWM4','Ax','Ay','Az','Wx','Wy','Wz','Roll_rate','Pitch_rate','Yaw_rate','PWM_M2','Thrust [N]'};
Acq_Data = array2table(Test_Thrust_M2_3_8N,'VariableNames',colNames)
filename = 'Test_Thrust_M2_3_8N';
save(filename, "Acq_Data")