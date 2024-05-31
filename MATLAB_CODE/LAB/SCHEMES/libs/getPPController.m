function [] = getPPController()
Ixx         =   0.07;        % moment of inertia (kg*m^2)
s           =   tf('s');
G           =   1/Ixx/s^2;
                
Ts_slk      =   0.01;
x0          =   [0;0];          % State Equilibrium Vector - Roll angles and rates
 
filter      =   1/(1+s/120);
filter_d    =   c2d(filter, Ts_slk);

R_tilde_pole = (9555* s^2 + 38220*s + 38220)/(s^2 + 250*s + 1.56e04)/s;

R_final     =   R_tilde_pole/(35/(1+s/120));  % zeros: -120, -1.98, -2.02 % poles: -0.07,-119.16, -130.77
R_final_D   =   c2d(R_final, Ts_slk);
R_final_ss  =   ss(R_final_D);
A           =   R_final_ss.A;
B           =   R_final_ss.B;
C           =   R_final_ss.C;
D           =   R_final_ss.D;

A_cond      =   A-B*inv(D)*C;
B_cond      =   B*inv(D);

%% To Workspace
assignin('base', 'A_cond', A_cond);
assignin('base', 'B_cond', B_cond);
assignin('base', 'C', C);
assignin('base', 'D', D);
assignin('base', 'filter_d', filter_d);

end