function [err,zHat,yHat] = costFunction3(x,tau,yMeas,Ts)
% compute the lest square error over the simulation

nSamples     = size(yMeas,2);

%% model parameters 
I           = x(1,1);
nParam      = 1;
z1          = x(nParam+1:nParam+nSamples,1)';
z2          = x(nParam+nSamples+1:nParam+nSamples+nSamples,1)';
z           = [z1;z2];

%% system matrixes - 2 possibility
A           = [0        1;
               0        0;];
B           = [0;       1/I];
C           = [1       0];
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
    if t < 10
        W = 10000;
    elseif t > 40
        W = 100;
    else
        W = 1;
    end
    err = err + (yMeas(:,t) - yHat(:,t))'*W*(yMeas(:,t) - yHat(:,t));
end
err = err/nSamples;
