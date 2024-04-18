clear all;
clc;
close all;

%% SYSTEM PARAMETERS
Ixx = 0.015;
A   = [0     1   ;
          0     0];
B = [0; 1/Ixx];
C = [1 0];
 G = tf(ss(A,B,C,0))
poles = [-50, -50.01];
K = place(A,B,poles);

% Optimal Allocator Init
Torque_req = 1;
k_pwm = 0.002;
f = [1, 1];
Aineq = [   1  0;
                -1  0;
                 0  1;
                 0 -1];
bineq = [2000;-1000;2000;-1000];
Aeq = [k_pwm -k_pwm];
beq = Torque_req;
x = linprog(f,Aineq,bineq,Aeq,beq);