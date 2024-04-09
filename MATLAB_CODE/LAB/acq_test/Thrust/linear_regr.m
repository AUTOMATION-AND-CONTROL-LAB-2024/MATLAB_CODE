clear all;
close all;
clc;
thrust = [0, 1, 2.7, 3,4.2,5.6]';
pwm = [1000, 1285, 1548, 1550, 1587,1846]';
delta_x = [2, 2.7]';
m = [0.49, 0.69]';
F = 9.81*m;
plot(delta_x, F);
%%plot(thrust, pwm);


K_spring = (delta_x'*delta_x)^(-1)*delta_x'*F;
K_motor = (pwm'*pwm)^(-1)*pwm'*thrust; % da aggiungere 1000

