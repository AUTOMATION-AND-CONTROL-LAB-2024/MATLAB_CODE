function [err,zHat,yHat] = costFunction2(x,tau,yMeas,Ts)
% compute the lest square error over the simulation

nSamples     = size(yMeas,2);

%% model parameters 
a0          = x(1,1);
a1          = x(2,1);
b0          = x(3,1);
b1          = x(4,1);
z1          = x(4+1:4+nSamples,1)';
z2          = x(4+nSamples+1:4+nSamples+nSamples,1)';
z           = [z1;z2];

%% system matrixes - 2 possibility
A           = [0        1;
               -a0      -a1;];
B           = [0;       1];
C           = [b0       b1];
D           = [0];

%% inizialize simulation output
zHat        = zeros(2,nSamples);
yHat        = zeros(1,nSamples);
z0          = z(:,1);
zHat(:,1)   = z0;
yHat(:,1)   = C*z0;

%% run simulation 
for t = 2:1:nSamples
    zHat(:,t)   = z(:,t-1) + Ts*(A*z(:,t-1) + B*tau(:,t-1));
    yHat(:,t)   = C*zHat(:,t);
end

%% error computation
err = 0;
for t = 1:1:nSamples
    if t < 60
        W = 1000;
    else
        W = 1;
    end
    err = err + (yMeas(:,t) - yHat(:,t))'*W*(yMeas(:,t) - yHat(:,t));
end
err = err/nSamples;
