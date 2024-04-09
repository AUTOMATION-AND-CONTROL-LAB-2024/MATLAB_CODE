function [K,feas,ris]=H2_control(A,B,C,D)

% The function uses LMIs to compute the control gain of a state-feedback
% control law 
% u=Kx
% x_dot=(A+BK)x

yalmip clear

ntot=size(A,1);
mtot=3; %mtot=size(vettore control variables)

% The design is centralized
Y   =   sdpvar(ntot);
L   =   sdpvar(mtot,ntot);
S   =   sdpvar(ntot);
gammaL  =   sdpvar(1);                                                     
alphaY  =   sdpvar(1);
%Q_sqrt=rand(ntot/2,mtot);
%R_sqrt=rand(ntot/2,ntot);

Q_sqrt=ones(ntot/2,ntot);
R_sqrt=ones(ntot/2,mtot);

C_h     =   0.1*[Q_sqrt;zeros(ntot/2,ntot)];  %C is nxn
D_h       =   0.1*[zeros(ntot/2,mtot);R_sqrt];  % D is nxm                       
                         
Bw      =   0.1*ones(ntot,ntot/2); %per ora il rumore è sul primo stato (così viene feasible, sennò no)

LMIconstr   =   [Y>=1e-2*eye(ntot)];
LMIconstr   =   LMIconstr + [[S, (C_h*Y + D_h*L);                                             % LMI for H2
                             (C_h*Y + D_h*L)', Y]>= 1e-2*eye(2*ntot)] ;
LMIconstr   =   LMIconstr + [A*Y + B*L + Y*A' + L'*B' + Bw*Bw' <= -1e-2*eye(ntot)];   % LMI for H2
LMIconstr   =   LMIconstr + [[gammaL*eye(ntot), L';                                         % LMI to min the control effort
                          L,                eye(mtot)] >= 1e-2*eye(ntot+mtot)];
LMIconstr   =   LMIconstr + [[alphaY*eye(ntot), eye(ntot);                                  % LMI to min the control effort
                          eye(ntot),        Y] >= 1e-2*eye(2*ntot)];
LMIconstr   =   LMIconstr + [gammaL>=0]+ [alphaY>=0];
f           =   trace(S) +1e-2*gammaL + 10*alphaY;

options     =   sdpsettings('solver','sdpt3'); %al posto di sdpt3, si potrebbe usare sedumi
J           =   optimize(LMIconstr,f,options);
feas        =   J.problem;
L           =   double(L);
Y           =   double(Y);

K           =   L/Y; %state-feedback gain

ris         =   trace(double(S))