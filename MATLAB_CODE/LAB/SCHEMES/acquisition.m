%% ACQUISITION FILE

colNames = {'time','PWM1','PWM2','PWM3','PWM4','a_b_x','a_b_y','a_b_z','w_b_p','w_b_q','w_b_r','Roll_rate','Pitch_rate','Yaw_rate','Roll','Pitch','Yaw','mf_b_x','mf_b_y','mf_b_z','phi','theta','psi', 'phi_rate','theta_rate','psi_rate'};
Acq_Data = array2table(Test,'VariableNames',colNames);
filename = "..\acq_test\Test_"+"000_400_1kH";
save(filename, "Acq_Data")

%% acquisition for control - there is th eRPy ref signal in additction

colNames = {'time','PWM1','PWM2','PWM3','PWM4','a_b_x','a_b_y','a_b_z','w_b_p','w_b_q','w_b_r','Roll_rate','Pitch_rate','Yaw_rate','Roll','Pitch','Yaw','mf_b_x','mf_b_y','mf_b_z','phi','theta','psi', 'phi_rate','theta_rate','psi_rate','roll_ref','pitch_ref','yaw_ref'};
Acq_Data = array2table(Test1,'VariableNames',colNames);
filename = "..\acq_test\Test_"+"PID_1dof_roll_sinewave";
save(filename, "Acq_Data");