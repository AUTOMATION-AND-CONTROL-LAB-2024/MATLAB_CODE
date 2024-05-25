function [err] = costFunction(x,tau,yMeas,Ts)
% compute the lest square error over the simulation

%% model parameters 
Ixx         =       x(1,1);                 %  moment of inertia (kg*m^2)

%% system matrixes - 1 possibility
A           = [0       1;
               0        0;];
B           = [0;       1;];
C           = [1/Ixx    0;];
D           = [0];

%% inizialize simulation output
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

%% error computation
err = 0;
for t = 2:1:nSample
    err = err + (yMeas(1,t) - yHat(1,t))*(yMeas(1,t) - yHat(1,t));
end
err = err/nSample;
