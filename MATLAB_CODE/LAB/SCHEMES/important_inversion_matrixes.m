%% compute the inversion of matrix Mtau_u: (mg/c_th*c_ps, tau_ph, tau_th, tau_ps)' = Mtau_u * (u1,u2,u3,u4)'
% syms k1 k2 k3 k4 l b
% Mtau_u = [k1      k2       k3       k4;
%           0       0        l*k3    -l*k4;
%          -l*k1    l*k2     0        0;
%          -b      -b        b        b;];*-
% Mtau_u'*inv(Mtau_u*Mtau_u')

%% compute the inversion matrix of J
% syms J11 J12 J13 J21 J22 J23 J31 J32 J33
% syms C11 C12 C13 C21 C22 C23 C31 C32 C33
% J = [J11 J12 J13;
%      J21 J22 J23;
%      J31 J32 J33;];
% C = [C11 C12 C13;
%      C21 C22 C23;
%      C31 C32 C33;];
% invJ = inv(J);