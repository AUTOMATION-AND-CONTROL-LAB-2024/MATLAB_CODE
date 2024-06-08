clear all;
clc;
%% PP
K = 0.08777160165775438;
tau1 = 0.768362201062388;
tau2 = 0.4773486513279449;
theta = 4.391660581719733;
s = tf('s');
num = K;
den = conv([tau1,1],[tau2,1]);
delay = theta;
Gs = tf(num,den);
wc_PP = bandwidth(Gs)
phi_PP = margin(Gs)
bode(Gs);
%% PID
K  = 0.09071944373419887;
tau1 = 0.7006324044217673;
tau2 = 0.24049058356078076;
theta = 7.884099504481733;
s = tf('s');
num = K;
den = conv([tau1,1],[tau2,1]);
delay = theta;
Gs = tf(num,den);
wc_PID = bandwidth(Gs)
phi_PID = margin(Gs)
bode(Gs);