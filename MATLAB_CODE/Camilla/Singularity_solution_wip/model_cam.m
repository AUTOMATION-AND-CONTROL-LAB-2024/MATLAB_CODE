function xdot = model_cam(x, tau, param)

% This is the model inserted in the simulink, 
% I'm uploading it in a separate file too for quick reading

% Inputs:   x: state vector
%           tau: torque vector
%           param: moment of inertia
% 
% Outputs:  xdot  (derivative of the state w.r.t. time)

%% Input Data

% Parameters
g        =       9.81;           %  gravity acceleration (m/s^2)
Ixx      =       param(1,1);     %  moment of inertia 
Iyy      =       param(2,1);     %  moment of inertia
Izz      =       param(3,1);     %  moment of inertia

% States
q0       =       x(1,1);     
q1       =       x(2,1);     
q2       =       x(3,1);       
q3       =       x(4,1);     
P        =       x(5,1);     
Q        =       x(6,1);     
R        =       x(7,1);

% torques
tau_1    =       tau(1,1);   %  roll torque 
tau_2    =       tau(2,1);   %  pitch torque 
tau_3    =       tau(3,1);   %  yaw torque

%% Define useful matrices

Quaternion_Multiplication       =      [0    -P    -Q    -R; 
                                        P     0     R    -Q; 
                                        Q    -R     0     P; 
                                        R     Q    -P     0];

Quaternion      =      [q0 q1 q2 q3]';

%% Model Equations

xdot     =       zeros(7,1);

xdot(1:4,1)     =     (-1/2)*Quaternion_Multiplication*Quaternion;
xdot(5:7,1)     =     [(Iyy-Izz)*Q*R/Ixx; (Izz-Ixx)*P*R/Iyy; (Ixx-Iyy)*P*Q/Izz] + [tau_1/Ixx; tau_2/Iyy; tau_3/Izz];

