%% Main - EKF 2.0
clear all
close all
clc

%%
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)

%% extraction of dataset from Test_RPY_quaternion
raw_data = load("RAW_DATA/Test_SENSORS_2.mat");
dataset = table2array(raw_data.Acq_Data);   %variable name "Acq_data"
[rows,colums] = size(dataset);

% delete the first zeros in the dataset
% i=1;
% while(dataset(i,2:colums) == zeros(1,colums-1))
% i = i+1;    
% end
% dataset = dataset(i:rows,:);                     % remove the zeros from dataset
% dataset(:,1) = dataset(:,1) - dataset(1,1);     % shift the time
% 
% % find the other zeros in the dataset
% for i = 1:1:size(dataset,1)
%     if dataset(i,2:colums) == zeros(1,colums-1)
%         break;
%     end
% end
% dataset = dataset(1:i-1,:);
% [rows,colums] = size(dataset);

% extraction of dataset
time            = dataset(:,1) - dataset(1,1);
IMU_Tend        = time(end,1);  
IMU_a_b         = [time, dataset(:,6:8)];
IMU_w_b         = [time, dataset(:,9:11)];
IMU_mf_b        = [time, dataset(:,18:20)];
IMU_roll        = [time, dataset(:,15)];
IMU_pitch       = [time, dataset(:,16)];
IMU_yaw         = [time, dataset(:,17)];
IMU_roll_rate   = [time, dataset(:,12)];
IMU_pitch_rate  = [time, dataset(:,13)];
IMU_yaw_rate    = [time, dataset(:,14)];  

%% Simulation
Ts_slk      =       0.01;           % sampling time (s)
Tend_slk    =       IMU_Tend;       % simulation time (s)

%% IMU parameter loading
IMU_data = load("IMUParameters.mat");
IMU_var_bias_matrix = table2array(IMU_data.IMU_var_bias);      % need IMU_var_bias table
clear IMU_data;

%% IMU parameters assignment
IMU_a_b_bias            = ones(3,1)*0.001;                  % bias in IMU linear acceleration measurement     (THEORY)
IMU_w_b_bias            = IMU_var_bias_matrix(:,2);         % bias in IMU angular velocity measurement 
IMU_mf_b_bias           = ones(3,1)*0.001;                  % bias in IMU magnetic field measurement          (THEORY)
IMU_a_b_variance        = IMU_var_bias_matrix(:,1);         % variance in IMU linear acceleration measurement
IMU_w_b_variance        = IMU_var_bias_matrix(:,3);         % variance in IMU angular velocity measurement
IMU_mf_b_variance       = ones(3,1)*0.001;                  % variance in IMU magnetic field measurement 

%% RPY computation
acc_pole                = 10;                               % pole [Hz] of the high-pass-filter in input to the <RPY_computation> block
vel_pole                = 20;
%% EKF2 parameters

% --------------------------------------------------------------------------------------------------------
% oss: Ts_EKF_meas must be a multiple of Ts_EKF_integr, example: Ts_EKF_meas = 10 * Ts_EKF_integr
Ts_EKF_integr      = 0.001;     % [s] Ts for the ODE integration 
Ts_EKF_meas        = 0.01;       % [s] Ts for measurement update
% --------------------------------------------------------------------------------------------------------

% RP_EKF
q_ph        = 630e-0;                 % q-elements related to phi states
q_th        = 700e-0;                 % q-elements related to theta states
q_bias_w_b  = 1e-7;                 % q-elements related to bias_wp, bias_wq, bias_wr (bias of wp,wq,wr of angular velocity vector)
Q_phth      = diag([q_ph,q_th,q_bias_w_b,q_bias_w_b,q_bias_w_b]);

r_ph        = 400e-0;                 % variance related to phi computation from IMU measurement
r_th        = 600e-0;                 % variance related to theta computation from IMU measurement
R_phth      = diag([r_ph,r_th]);

ph0         = 0;                    % initial guess of phi angle
th0         = 0;                    % initial guess of theta angle
bias_wp0    = IMU_w_b_bias(1,1);    % initial guess of bias in p direction (of vector w angular velocity) can be estimated with measurements
bias_wq0    = IMU_w_b_bias(2,1);    % initial guess of bias in q direction (of vector w angular velocity) can be estimated with measurements
bias_wr0    = IMU_w_b_bias(3,1);    % initial guess of bias in r direction (of vector w angular velocity) can be estimated with measurements
x0_phth     = [ph0;th0;bias_wp0;bias_wq0;bias_wr0];

P0_ph       = 200;
P0_th       = 600;
P0_bias_wp  = IMU_w_b_variance(1,1);
P0_bias_wq  = IMU_w_b_variance(2,1);
P0_bias_wr  = IMU_w_b_variance(3,1);
P0_phth     = diag([P0_ph,P0_th,P0_bias_wp,P0_bias_wq,P0_bias_wr]);

% Y_EKF
q_ps        = 100e-0;                    % q-elements related to yaw state
r_ps        = 600e+0;                    % variance related to psi computation from IMU measurement
x0_ps       = 0;                          % initial guess of psi angle
P0_ps       = 100;

% RPY_rate EKF
q_ph_rate       = 900;                    % q-elements related to phi_rate,theta,yaw
q_th_rate       = 900;                    % q-elements related to theta_rate
q_ps_rate       = 900;                    % q-elements related to yaw_rate
Q_rate          = diag([q_ph_rate,q_th_rate,q_ps_rate]);

r_ph_rate        = 40;                    % variance related to phi computation from IMU measurement
r_th_rate        = 40;                    % variance related to theta computation from IMU measurement
r_ps_rate        = 40;                    % variance related to psi computation from IMU measurement
R_rate           = diag([r_th_rate,r_th_rate,r_ps_rate]);

ph_rate0         = IMU_roll(1,2);         % initial guess of phi angle
th_rate0         = IMU_pitch(1,2);        % initial guess of theta angle
ps_rate0         = IMU_yaw(1,2);          % initial guess of psi angle
x0_rate_EKF      = [ph_rate0;th_rate0;ps_rate0;];

P0_ph_rate       = 10;
P0_th_rate       = 10;
P0_ps_rate       = 10;
P0_rate          = diag([P0_ph_rate,P0_th_rate,P0_ps_rate]);

%% Error computation
phi_estim       = out.simout(:,1);
theta_estim     = out.simout(:,2);
psi_estim       = out.simout(:,3);
phiRate_estim   = out.simout(:,4);
thetaRate_estim = out.simout(:,5);
psiRate_estim   = out.simout(:,6);

N               = length(phi_estim);
phi_error       = sqrt((IMU_roll(:,2) - phi_estim)'*(IMU_roll(:,2) - phi_estim)/N);
theta_error     = sqrt((IMU_pitch(:,2) - theta_estim)'*(IMU_pitch(:,2) - theta_estim)/N);
psi_error       = sqrt((IMU_yaw(:,2) - psi_estim)'*(IMU_yaw(:,2) - psi_estim)/N);

fprintf('roll error:  %.2f \n',phi_error);
fprintf('pitch error: %.2f \n',theta_error);
fprintf('yaw error:   %.2f \n',psi_error);
fprintf('----------------------------------------- \n');

%% Plots
close all

figure()
subplot(3,1,1)
plot(time(ni:nf),[phi_estim(ni:nf),IMU_roll(ni:nf,2)]*180/pi,'LineWidth',1.3);
grid on;
ax = gca;
set(ax.XLabel, 'Interpreter', 'latex'); set(ax.YLabel, 'Interpreter', 'latex'); set(ax.Title, 'Interpreter', 'latex');
title("roll angle");
xlabel("time [s]"); ylabel("roll [deg]"); legend("EKF-roll","IMU-roll");
xlim([ni,nf]*Ts_slk);

subplot(3,1,2)
plot(time(ni:nf),[theta_estim(ni:nf),IMU_pitch(ni:nf,2)]*180/pi,'LineWidth',1.3);
grid on;
ax = gca;
set(ax.XLabel, 'Interpreter', 'latex'); set(ax.YLabel, 'Interpreter', 'latex'); set(ax.Title, 'Interpreter', 'latex');
title("pitch angle");
xlabel("time [s]"); ylabel("pitch [deg]"); legend("EKF-pitch","IMU-pitch");
xlim([ni,nf]*Ts_slk);

subplot(3,1,3)
plot(time(ni:nf),[psi_estim(ni:nf),IMU_yaw(ni:nf,2)]*180/pi,'LineWidth',1.3);
grid on;
ax = gca;
set(ax.XLabel, 'Interpreter', 'latex'); set(ax.YLabel, 'Interpreter', 'latex'); set(ax.Title, 'Interpreter', 'latex');
title("yaw angle");
xlabel("time [s]"); ylabel("yaw [deg]"); legend("EKF-yaw","IMU-yaw");
xlim([ni,nf]*Ts_slk);

%% Save the result
close all;
% ---------------------------------------------------------------------------------------------
% Define the X and Y values
ni = 50/Ts_slk;
nf = 67/Ts_slk;
x = time(ni:nf);
% y = [phi_estim(ni:nf), IMU_roll(ni:nf,2)] * 180 / pi;
% y = [theta_estim(ni:nf), IMU_pitch(ni:nf,2)] * 180 / pi;
% y = [psi_estim(ni:nf), IMU_yaw(ni:nf,2)] * 180 / pi;
% y = [phiRate_estim(ni:nf), IMU_roll_rate(ni:nf,2)] * 180 / pi;
% y = [thetaRate_estim(ni:nf), IMU_pitch_rate(ni:nf,2)] * 180 / pi;
y = [psiRate_estim(ni:nf), IMU_yaw_rate(ni:nf,2)] * 180 / pi;

% ---------------------------------------------------------------------------------------------
% Create the Figure
fig = figure();
% Set the background color
fig.Color = [0.94, 0.94, 0.94]; % Grey-background, [1, 1, 1] White-background
% Figure - Position and Size (Figure Properties)
fig.Units = 'centimeters';
fig.Position = [1, 1, 40, 6]; % [left, bottom, width, height]

% ---------------------------------------------------------------------------------------------
% Create the Plot
p = plot(x,y);
% Set the line width
p(1).LineWidth = 1.3;
p(2).LineWidth = 1.3;

% ---------------------------------------------------------------------------------------------
% Get the Current Axes (handle)
ax = fig.CurrentAxes;

% Axis - Appearence (NumericRuler Properties)
% Set the Color of the axes
ax.XAxis.Color = [0.15 0.15 0.15];
ax.YAxis.Color = [0.15 0.15 0.15];
% Set the Line Width of the axes
ax.XAxis.LineWidth = 0.7;
ax.YAxis.LineWidth = 0.7;
% Set the Font Name of the axes (Ticks)
ax.XAxis.FontName = 'Helvetica';
ax.YAxis.FontName = 'Helvetica';
% Set the Font Size of the axes (Ticks)
ax.XAxis.FontSize = 14;
ax.YAxis.FontSize = 14;

% Axis - Labels (NumericRuler Properties)
% Set the Interpreter of the axes' labes
ax.XLabel.Interpreter = 'latex';
ax.YLabel.Interpreter = 'latex';
% Set the Font Name of the axes' labels
ax.XAxis.FontName = 'Helvetica';
ax.YAxis.FontName = 'Helvetica';
% Set the Font size of the axes'labels
ax.XAxis.Label.FontSize = 16;
ax.YAxis.Label.FontSize = 16;
% Set the Label of the axes
ax.XAxis.Label.String = 'Time [\textit{s}]';
ax.YAxis.Label.String = '$\dot{\psi}$ [\textit{deg/s}]';

% Axis - Ticks (NumericRuler Properties)
% Set the Ticks Values of the axes
dXTick   = 1;
dYTick   = 120;
minX     = ceil(min(min(x)));
maxX     = ceil(max(max(x)));
minY     = floor(min(min(y)) - abs(min(min(y)))*0.02);
maxY     = max(max(y));
ax.XAxis.TickValues = minX:dXTick:maxX;
ax.YAxis.TickValues = minY + (0:dYTick:ceil(abs(maxY-minY)/dYTick)*dYTick);
% Set the Ticks Exponent
ax.XAxis.Exponent = 0;  % The base value is always 10. However, you can change the exponent value by setting the Exponent property.
ax.YAxis.Exponent = 0;  % If the exponent value is 0, then the exponent label does not display.
  
% Axis - Scale and Direction (NumericRuler Properties)
% Set the Limits of the axes
ax.XAxis.Limits = [min(ax.XTick), max(ax.XTick)];
ax.YAxis.Limits = [min(ax.YTick), max(ax.YTick)];

% Grids (Axes Properties) 
% Set the Grid of the axes
ax.XGrid = 'on';
ax.YGrid = 'on'; 
% Set the Grid Line Width
ax.GridLineWidth = 1.0;
% Set the Grid Color
ax.GridColor = [0.15 0.15 0.15];

% Title (Axes Properties) 
% Set the interpreter to 'latex'
ax.Title.Interpreter = 'latex';
% Set the Font Name
ax.Title.FontName = 'Helvetica';
% Set the Font Size
ax.Title.FontSize = 16;
% Set the Title
ax.Title.String = 'Yaw rate';

% Box Styling (Axes Properties)
% Set the background color of the area inside the plot 
ax.Color = [1, 1, 1]; % White background
% Turn the box off
ax.Box = 'off';

% ---------------------------------------------------------------------------------------------
% Create the Legend
lgd = legend("show");

% Legend (Legend Properties)
% Set the interpreter to 'latex'
lgd.Interpreter = 'latex';
% Set the Font Name
lgd.FontName = 'Helvetica';
% Set the Font Size
lgd.FontSize = 9;
% Set the Legend
lgd.String = {'YawRate$_{EKF}$','YawRate$_{IMU}$'};
% Set the location of the legend
lgd.Location = 'northeast';
% Turn the box on
lgd.Box = 'on';

% ---------------------------------------------------------------------------------------------
% export the image
exportgraphics(fig,"results_and_plots/plotYawRate2.jpg","Resolution",300);