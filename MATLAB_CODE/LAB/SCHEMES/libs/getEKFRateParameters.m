function [] = getEKFRateParameters()
%% RPY_rate EKF
q_ph_rate       = 900;                    % q-elements related to phi_rate,theta,yaw
q_th_rate       = 900;                    % q-elements related to theta_rate
q_ps_rate       = 900;                    % q-elements related to yaw_rate
Q_rate          = diag([q_ph_rate,q_th_rate,q_ps_rate]);

r_ph_rate        = 40;                    % variance related to phi computation from IMU measurement
r_th_rate        = 40;                    % variance related to theta computation from IMU measurement
r_ps_rate        = 40;                    % variance related to psi computation from IMU measurement
R_rate           = diag([r_th_rate,r_th_rate,r_ps_rate]);

ph_rate0         = 0;         % initial guess of phi angle
th_rate0         = 0;        % initial guess of theta angle
ps_rate0         = 0;          % initial guess of psi angle
x0_rate_EKF      = [ph_rate0;th_rate0;ps_rate0;];

P0_ph_rate       = 10;
P0_th_rate       = 10;
P0_ps_rate       = 10;
P0_rate          = diag([P0_ph_rate,P0_th_rate,P0_ps_rate]);
end