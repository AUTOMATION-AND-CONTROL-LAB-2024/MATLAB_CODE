function [err] = costFunction(x,u,yMeas,param,Ts)
% compute the lest square error over the simulation

%% Model parameters 
Ixx         =       x(1,1);                 %  moment of inertia (kg*m^2)
l           =       param(4,1);             %  quadcopter arm (m)
k1          =       param(5,1);             %  lift constant motor 1
k2          =       param(6,1);             %  lift constant motor 2
k3          =       param(7,1);             %  lift constant motor 3
k4          =       param(8,1);             %  lift constant motor 4

Mtau_u      = [0       0        l*k3    -l*k4];

A           = [0       1;
               0       0;];
B           = [0;
               1/Ixx;];
C           = [1       0;];
D           = [0];
%% Inizialize simulation output
nSample     = size(yMeas,2);
zHat        = zeros(2,nSample);
yHat        = zeros(2,nSample);
z0          = [x(2,1); x(3,1)];
zHat(:,1)   = z0;
yHat(:,1)   = C*z0;
%% run simulation 
for t = 2:1:nSample
    tau         = Mtau_u*u(:,t-1);
    zHat(:,t)   = zHat(:,t-1) + Ts*(A*zHat(:,t-1) + B*tau);
    yHat(:,t)   = C*zHat(:,t);
end

%% Error computation
err = 0;
for t = 2:1:nSample
    err = err + (yMeas(1,t) - yHat(1,t))*(yMeas(1,t) - yHat(1,t));
end
err = err/nSample;
