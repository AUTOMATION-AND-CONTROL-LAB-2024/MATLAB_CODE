clear all;
close all;
clc;
thrust = [0, 1, 2.7, 3,4.2,5.6]';
pwm = [1000, 1285, 1548, 1550, 1587,1846]';
thrust_report = [0, 0.5, 1.5, 2, 2.7, 3, 4.2, 5, 5.6, 6]';
pwm_report = [1000, 1115, 1285, 1342, 1450, 1550, 1587, 1672, 1846, 1953]';
delta_x = [2, 2.7]';
m = [0.49, 0.69]';
F = 9.81*m;
%%plot(delta_x, F);
figure (1);
plot(thrust_report, pwm_report,'*');
grid on;
title("THRUST-PWM COEFFICIENT");
xlabel("PWM");
ylabel("THRUST");


K_spring = (delta_x'*delta_x)^(-1)*delta_x'*F;
K_motor = (pwm'*pwm)^(-1)*pwm'*thrust; % da aggiungere 1000

