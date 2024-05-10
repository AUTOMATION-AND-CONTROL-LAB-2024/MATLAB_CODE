function [K,rho,feas,ris]=LMI_CT_all(A,B,C,N,ContStruc,theta,alpha,radius)
% Computes, using LMIs, the distributed "state feedback" control law for the continuous-time system, with reference to the control
% information structure specified by 'ContStruc'.
%
% Inputs:
% - A: system matrix.
% - B: input matrices (i.e., B{1},..., B{N} are the input matrices of the decomposed system, one for each channel).
% - C: output matrices  (i.e., C{1},..., C{N} are the output matrices of the decomposed system, one for each channel, where [Cdec{1}',...,
% Cdec{N}']=I).
% - N: number of subsystems.
% - ContStruc: NxN matrix that specifies the information structure
% constraints (ContStruc(i,j)=1 if communication is allowed between channel
% j to channel i, ContStruc(i,j)=0 otherwise).
%-theta: semi-angle of sector
%
% Output:
% - K: structured control gain
% - rho: spectral abscissa of matrix (A+B*K) - note that [C{1}',...,
% C{N}']=I
% - feas: feasibility of the LMI problem (=0 if yes)

Btot=[];
for i=1:N
    m(i)=size(B{i},2);
    n(i)=size(C{i},1);
    Btot=[Btot,B{i}];
end
ntot=size(A,1);
mtot=sum(m);

yalmip clear

if ContStruc==ones(N,N)
    % Centralized design
    Y   =   sdpvar(ntot);
    L   =   sdpvar(mtot,ntot);
    S   =   sdpvar(ntot);
else
    % Decentralized/distributed design
    Y   =   [];
    L   =   sdpvar(mtot,ntot);
    S   =   sdpvar(ntot);
    minc=0;
    for i=1:N
        Y=blkdiag(Y,sdpvar(n(i)));
        ninc=0;
        for j=1:N
            if ContStruc(i,j)==0
                L(minc+1:minc+m(i),ninc+1:ninc+n(j))=zeros(m(i),n(j));
            end
            ninc=ninc+n(j);
        end
        minc=minc+m(i);
    end  
end
D       =   [zeros(ntot/2,mtot); randn(ntot/2,mtot)>0];                    % D is nxm
C_h     =   [randn(ntot/2,ntot)>0;zeros(ntot/2,ntot)];                     % C is nxn
Bw      =   randn(ntot);                                                   % H control
gammaL  =   sdpvar(1);                                                     
alphaY  =   sdpvar(1);
Dw      =   eye(ntot)>0;                                                   % H_infinity
gamma   =   sdpvar(1);                                                     % H_infinity
C_hinf  =   eye(ntot)>0;                                                   % H_infinity

LMIconstr   =   [Y*A'+A*Y+Btot*L+L'*Btot'<=-1e-2*eye(ntot)] + [Y>=1e-2*eye(ntot)];          % LMI for AS
% LMIconstr   =   LMIconstr + [[S, (C_h*Y + D*L);                                            % LMI for H2
%                               (C_h*Y + D*L)', Y]>= 1e-2*eye(2*ntot)] ;
% LMIconstr   =   LMIconstr + [A*Y + Btot*L + Y*A' + L'*Btot' + Bw*Bw' <= -1e-2*eye(ntot)];   % LMI for H2
LMIconstr   =   LMIconstr + [[gammaL*eye(ntot), L';                                         % LMI to min the control effort
                          L,                eye(mtot)] >= 1e-2*eye(ntot+mtot)];
LMIconstr   =   LMIconstr + [[alphaY*eye(ntot), eye(ntot);                                  % LMI to min the control effort
                          eye(ntot),        Y] >= 1e-2*eye(2*ntot)];
LMIconstr   =   LMIconstr + [gammaL>=0]+ [alphaY>=0];
% LMIconstr   =   LMIconstr+[[sin(theta)*(A*Y + Y*A' + Btot*L + L'*Btot'), cos(theta)*(A*Y - Y*A' + Btot*L - L'*Btot');       % LMI for the sector                    
%                               cos(theta)*(-A*Y + Y*A' - Btot*L + L'*Btot'), sin(theta)*(A*Y + Y*A' + Btot*L + L'*Btot')] <= -1e-2*eye(2*ntot)];
% LMIconstr=LMIconstr+[[(radius^2-alpha^2)*Y-alpha*(A*Y+Y*A'+Btot*L+L'*Btot'), A*Y+Btot*L;     % LMI for circle of radius rho and centered in -alpha
%                     (A*Y+Btot*L)', Y]>= 1e-2*eye(2*ntot)]+[Y>=1e-2*eye(ntot)];

LMIconstr   =   LMIconstr + [[Y*A' + A*Y + Btot*L + L'*Btot',   Bw ,  Y*C_hinf'+L'*D';         % LMI for Hinfinity
                              Bw',            -gamma*eye(ntot),    Dw';
                              C_hinf*Y+D*L ,  Dw ,   -gamma*eye(ntot)] <= -1e-2*eye(3*ntot)];

f           =   2e5*gammaL + 1e6*alphaY + gamma;

% f           =   2e5*gammaL + 1e6*alphaY+ trace(S);

options     =   sdpsettings('solver','sdpt3');
J           =   optimize(LMIconstr,f,options);
feas        =   J.problem;
L           =   double(L);
Y           =   double(Y);

K           =   L/Y;
rho         =   max(real(eig(A+Btot*K)));
ris         =   trace(double(S))