function [c,ceq] = nonlinearConstraint2(x,tau,yMeas,Ts)
% nonlinear constraint: enforce the system dynamics: x(t+1) = f(x(t),u(t))

nSamples    = size(yMeas,2);

[~,zHat,yHat]  = costFunction2(x,tau,yMeas,Ts);
z1          = x(4+1:4+nSamples,1)';
z2          = x(4+nSamples+1:4+nSamples+nSamples,1)';
zHat1       = zHat(1,:);
zHat2       = zHat(2,:);

ceq1        = (z1 - zHat1)';
ceq2        = (z2 - zHat2)';

cmax        = (+yHat - (+0.0873))';
cmin        = (-yHat + (-0.0001))';

c           = [cmax;cmin];
ceq         = [ceq1;ceq2;];
end