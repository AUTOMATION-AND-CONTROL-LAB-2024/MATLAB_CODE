%% Script - Quadcopeter Parameters Identification
clear all
close all
clc
%% Model parameters
getQuadcopterParameters();
Ts_slk = 0.01;

%% extraction of measurements from data
raw_data    = load("RAW_DATA/Test_PID_1dof");  
% raw_data    = load("RAW_DATA/Test_system_controller_small_oscillation"); 
dataset     = table2array(raw_data.Acq_Data);

%% signals division
delta       = 10;                          
nSamples    = length(dataset(:,1));                                
samples     = 1:delta:nSamples;                               % n° of samples [adim]
time        = dataset(samples,1)';                            % time [s]                           
u1          = dataset(samples,2)';                            % pwm  [adim]
u2          = dataset(samples,3)';                            % pwm  [adim]
u3          = dataset(samples,4)';                            % pwm  [adim]
u4          = dataset(samples,5)';                            % pwm  [adim]
u           = [u1; u1; u3; u4] - 1000;
rollMeas    = dataset(samples,15)'+3.9*pi/180;                % roll [rad]
rolldotMeas = dataset(samples,12)';                           % roll rate [rad]
yRef        = dataset(samples,27)';                           % roll ref [rad]

% roll torque computation
l  = param(4,1);
k3 = param(7,1);
k4 = param(8,1);
Mtau_u      = [0       0        l*k3    -l*k4];
tau = zeros(1,samples(end));
for t = 1:1:samples(end)
    tau(1,t) =  Mtau_u*u(:,t);
end

% filter the signals
u1          = lowpass(u1,40,1/Ts_slk);
u2          = lowpass(u2,40,1/Ts_slk);
u3          = lowpass(u3,40,1/Ts_slk);
u4          = lowpass(u4,40,1/Ts_slk);
u           = [u1; u1; u3; u4] - 1000;
rollMeas    = lowpass(rollMeas,40,1/Ts_slk);
%% plot to select the time interval
figure(1)
subplot(4,1,1);
plot(samples, (yRef)*180/pi );
title("y ref");
xlabel("n° sample");
ylabel("[deg]");

subplot(4,1,2);
plot(samples, (rollMeas)*180/pi );
title("roll meas");
xlabel("n° sample");
ylabel("[deg]");

subplot(4,1,3);
plot(samples, (rolldotMeas) );
title("rolldot meas");
xlabel("n° sample");
ylabel("[deg/s]");

subplot(4,1,4);
plot(samples, tau);
title("tau roll")
xlabel("n° sample");
ylabel("[Nm]");
%% define the time interval
ni   = 5000; % 5500 if 1:10:length(dataset(:,1))
nf   = 5800; % 7000; 

%% signal extraction in the time interval selected
delta       = 10;                          
nSamples    = length(dataset(:,1));                                
samples     = ni:delta:nf;                                    % n° of samples [adim]
u1          = dataset(samples,2)';                            % pwm  [adim]
u2          = dataset(samples,3)';                            % pwm  [adim]
u3          = dataset(samples,4)';                            % pwm  [adim]
u4          = dataset(samples,5)';                            % pwm  [adim]
rollMeas    = dataset(samples,15)'+3.9*pi/180;                % roll [rad]
rolldotMeas = dataset(samples,12)';                           % roll rate [rad]
yRef        = dataset(samples,27)';                           % roll ref [rad]

tau         = tau(1,samples);

%% plot the selected time interval
figure(2)
subplot(4,1,1)
plot(ni+samples, (yRef)*180/pi );
title("y ref");
xlabel("n° sample");
ylabel("[deg]");

subplot(4,1,2)
plot(ni+samples, (rollMeas) );
title("roll meas");
xlabel("n° sample");
ylabel("[deg]");

subplot(4,1,3)
plot(ni+samples, (rolldotMeas) );
title("rolldot meas");
xlabel("n° sample");
ylabel("[deg/s]");

subplot(4,1,4)
plot(samples, tau);
title("tau roll");
xlabel("n° sample");
ylabel("[Nm]");

%% discretization
% syms s z I a b c d Ts
% G1 = 1/(I*s^2)
% G2 = (a+b*s)/(I*s^2+c*s+d)
% s  = (z-1)/Ts
% G1D = subs(G1,s)
% G2D = subs(G2,s)

%% constrained optimization
A   = [% +1  0 0 0              zeros(1,nSamples*2);
         -1  0 0 0              zeros(1,nSamples*2);
       %  0  1 0 0              zeros(1,nSamples*2); 
          0 -1 0 0              zeros(1,nSamples*2);
          zeros(nSamples,4)     +eye(nSamples)              zeros(nSamples,nSamples);
          zeros(nSamples,4)     -eye(nSamples)              zeros(nSamples,nSamples);
          zeros(nSamples,4)     zeros(nSamples,nSamples)    +eye(nSamples);
          zeros(nSamples,4)     zeros(nSamples,nSamples)    -eye(nSamples);
      ];
b   = [% 0;
         0;
       % 0;
         0;
        (+1)*ones(nSamples,1)*(+15);
        (-1)*ones(nSamples,1)*(-15);
        (+1)*ones(nSamples,1)*(+20);
        (-1)*ones(nSamples,1)*(-20)
      ];
Aeq = []; beq = []; lb = []; ub = [];
nonlcon = @(x)nonlinearConstraint2(x,tau,rollMeas,Ts_slk*10);
fun     = @(x)costFunction2(x,tau,rollMeas,Ts_slk*10); 

a0_0    = 0.1;
a1_0    = 0.1;
b0_0    = 2;
b1_0    = 0.1;
z_0     = rollMeas';
% zdot_0  = zeros(nSamples,1);
zdot_0(1:60,1)         = zeros(60,1);
zdot_0(61:nSamples,1)  = rolldotMeas(1,61:nSamples)';
x0      = [a0_0;a1_0;b0_0;b1_0;z_0;zdot_0];
% x0      = xOld;

options = optimoptions('fmincon','Display','iter','Algorithm','sqp');
options.MaxFunctionEvaluations = 1e10;
options.MaxIterations = 1e5;
options.FunctionTolerance = 1e-6;

x = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,nonlcon,options);

%%
[err,zHat,yHat] = costFunction2(x,tau,rollMeas,Ts_slk);
figure(3)
hold on;
plot(samples, (rollMeas)*180/pi);
plot(samples, (yHat)*180/pi);
title("roll meas");
xlabel("n° sample");
ylabel("[deg]");
legend("roll meas","yHat");

xOld = x;

figure(4)
subplot(2,1,1)
plot(samples, (zHat(1,:)));
title("zHat");
xlabel("n° sample");
ylabel("[adim]");

subplot(2,1,2)
plot(samples, zHat(2,:));
title("zdotHat");
xlabel("n° sample");
ylabel("[adim]");