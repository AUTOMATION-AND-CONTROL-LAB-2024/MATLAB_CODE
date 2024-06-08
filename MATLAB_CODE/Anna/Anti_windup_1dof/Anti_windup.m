clear all
close all
clc

%% General data
g           =       9.81;                   %  gravity acceleration (m/s^2)
mf          =       [22602; 0; -42062;];    %  earth magnetic field (in inertia frame) (nT) (1nT = 10^-5 Gauss)
Ixx         =       0.055;                  %  moment of inertia (kg*m^2)
Iyy         =       0.055;                  %  moment of inertia (kg*m^2)
Izz         =       0.03;                   %  moment of inertia (kg*m^2)
l           =       0.25;                   %  quadcopter arm (m)
k1          =       0.00684324;             %  lift constant motor 1
k2          =       0.00703859;             %  lift constant motor 2
k3          =       0.00814964;             %  lift constant motor 3
k4          =       0.00746697;             %  lift constant motor 4
b           =       1.14e-7;                %  drag constant
m           =       0.61+0.064*4;           %  mass (kg)
param       =       [Ixx;Iyy;Izz;l;k1;k2;k3;k4;b;m];


s           =   tf('s');
Ts_slk      =   0.01;
Tend_slk    =   400;
x0          =   [0;0];          % State Equilibrium Vector - Roll angles and rates
tau_r       =   0.01;


%% FINALE CHE FUNZIONA PID
% %% PID Parameters
% Ixx         =   0.07;  %  moment of inertia (kg*m^2)
% G           =   1/Ixx/s^2;
% 
% Ts_slk      =   0.001;
% s           =   tf('s');
% 
% Kc = 1e-0*Ixx;
% tau_i = 0.5;    
% tau_d = 0.5;    
% 
% % 0.8 con gain 20
% % 0.4 con gain 45
% % 0.5 con gain 35 molto good
% % 0.2 con gain -
% 
% PID = Kc * (tau_i*s+1) * (tau_d*s+1) / (s) / (1+s/130);
% filter = 1/(1+s/120);
% PID_D = c2d(PID, Ts_slk);
% filter_d = c2d(filter, Ts_slk);
% PID_ss      =   ss(PID_D);
% A           =   PID_ss.A;
% B           =   PID_ss.B;
% C           =   PID_ss.C;
% D           =   PID_ss.D;
% 
% A_cond      =   A-B*inv(D)*C;
% B_cond      =   B*inv(D);
% 
% 
% L_PID =35*G*PID*filter;
% figure(1)
% bode(L_PID);
% title("Bode - L(s) PID controller")
% grid  on
% figure(3)
% bode(G*PID);
% grid  on

%% POLE placement with transfer function DA TESTARE IL 28/05
% Ixx         =   0.07;  %  moment of inertia (kg*m^2)
% s           =   tf('s');
% G           =   1/Ixx/s^2;
% 
% Ts_slk      =   0.001;
% 
% 
% filter = 35/(1+s/120);
% filter_d = c2d(filter, Ts_slk);
% % % 35*(1+0.5*s)^2+s^3*(1+s/130)*(1+s/120) % L_PID_num+L_PID_den
% % r= roots([1/15600 250/15600 1 136500/15600 546000/15600 546000/15600]); % roots in closed loop (num+Den) del PID
% % % che può essere riscritto in modo da avere coefficiente 1 che moltiplica s^5
% % P= (s-r(1))*(s-r(2))*(s-r(3))*(s-r(4))*(s-r(5));
% % 
% % % posso provare ad usare P(s) per la diophantine equation del pole placement with TF
% % Column_R = [1 250 (1.56e04-1.137e-13i) (1.365e05-1.625e-13i)*Ixx 5.46e05*Ixx 5.46e05*Ixx]';
% % 
% % R_pole = (Column_R(4)*s^2+Column_R(5)*s+Column_R(6))/(Column_R(1)*s^2+Column_R(2)*s+Column_R(3));
% % 
% % % to remove the complex coniugate parts that actually are negligigble we
% % % simplify as:
% R_pole_simply= (9555* s^2 + 38220*s + 38220)/(s^2 + 250*s + 1.56e04);
% 
% R_tilde_pole = R_pole_simply/s;
% L_pole = R_tilde_pole*G; %% you can see that it's the same of L_PID
% figure(2)
% bode(L_pole);
% title("Bode - L(s) Pole Placement controller")
% grid  on
% 
% % % So, now we need to use R_tilde_pole in the scheme with G
% % % We can build the anti windup scheme as we did for the PID
% % % but D results =0. so i try to remove the filter to see what happens
% R_final     =   R_tilde_pole/filter; % zeros: -120, -1.98, -2.02 % poles: -0.07,-119.16, -130.77
% R_final_D   =   c2d(R_final, Ts_slk);
% R_final_ss  =   ss(R_final_D);
% A           =   R_final_ss.A;
% B           =   R_final_ss.B;
% C           =   R_final_ss.C;
% D           =   R_final_ss.D;
% 
% A_cond      =   A-B*inv(D)*C;
% B_cond      =   B*inv(D);
% % 
% % figure(4)
% % bode(G*R_final);
% % grid  on
% 
% % figure(5)
% % bode(PID);
% % figure(6)
% % bode(R_final);

%% H2 DA TESTARE IL 28/05
Ixx         =   0.07;  %  moment of inertia (kg*m^2)
s           =   tf('s');
G           =   1/Ixx/s^2;

Ts_slk      =   0.01;


load("stable_sys_H2_1dof_new_Ixx")
load("K_H2_1dof_new_Ixx.mat")
filter =35/(1+s/120); % con 62.5 la L è identica
filter_d = c2d(filter, Ts_slk);
R_H2= filter*(s+2)^2/(s+130)/s^3*(s^2+3.279*s+3.211);
L_H2 =R_H2*stable_sys;
figure(7)
bode(L_H2)  % you can see it's the same of PID and pole
title("Bode - L(s) H2 controller")
grid  on


% for the scheme:
R_final     =   (s+2)^2/(s+130)/s^3*(s^2+3.279*s+3.211); 
R_final_D   =   c2d(R_final, Ts_slk);
R_final_ss  =   ss(R_final_D);
A           =   R_final_ss.A;
B           =   R_final_ss.B;
C           =   R_final_ss.C;
D           =   R_final_ss.D;

A_cond      =   A-B*inv(D)*C;
B_cond      =   B*inv(D);