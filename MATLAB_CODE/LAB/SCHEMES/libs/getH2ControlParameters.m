function [] = getH2ControlParameters()
%% H2 Control
Ixx         =   0.07;  %  moment of inertia (kg*m^2)
s           =   tf('s');
G           =   1/Ixx/s^2;
                
Ts_slk      =   0.01;
x0          =   [0;0];          % State Equilibrium Vector - Roll angles and rates

filter = 1/(1+s/120);
filter_d = c2d(filter, Ts_slk);


R_final     =   (s+2)^2/(s+130)/s^3*(s^2+3.279*s+3.211);
R_final_D   =   c2d(R_final, Ts_slk);
R_final_ss  =   ss(R_final_D);
A           =   R_final_ss.A;
B           =   R_final_ss.B;
C           =   R_final_ss.C;
D           =   R_final_ss.D;

A_cond      =   A-B*inv(D)*C;
B_cond      =   B*inv(D);

K_H2_1dof = load("K_H2_1dof_new_Ixx.mat");
%% To Workspace
assignin('base', 'A_cond', A_cond);
assignin('base', 'B_cond', B_cond);
assignin('base', 'C', C);
assignin('base', 'D', D);
assignin('base', 'filter_d', filter_d);
assignin('base', 'K', K_H2_1dof.K);

end