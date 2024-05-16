function [Difm]=di_fixed_modes(A,B,C,rounding_n)
% Computes the fixed modes of the system, with reference to the control
% information structure specified by 'ContStruc'.
%
% Inputs:
% - A: system matrix - either continuous-time or discrete-time.
% - B: input matrices - either continuous-time or discrete-time -
% (i.e., B{1},..., B{N} are the input matrices of the decomposed system, one for each channel).
% - Caggr: output matrices - either continuous-time or discrete-time -
% (i.e., C{1},..., C{N} are the output matrices of the decomposed
% system, one for each channel).
% - N: number of subsystems.
% - ContStruc: NxN matrix that specifies the information structure
% constraints (ContStruc(i,j)=1 if communication is allowed between channel
% j to channel i, ContStruc(i,j)=0 otherwise).
% - rounding_n: the eigenvalues are rounded at the nth decimal place 
%
% Output:
% - Difm: vector containing the fixed modes (if empty, there are no FMs)

N=1;

m_tot=size(B,2);
p_tot=size(C,1);

Difm=round(eig(A),rounding_n);
nelD=length(Difm);

% ContStruc=ones(4,6);

kend=1000;
k=0;
while (nelD~=0)&&(k<=kend)
    k=k+1;
    K=zeros(m_tot,p_tot);
    m_inc=0;
    for i=1:N
        p_inc=0;
        for j=1:N
            K(m_inc+1,p_inc+1)=100*randn(1);
            p_inc=p_inc+1;
        end
        m_inc=m_inc+1;
    end
    eF=round(eig(A+B*K*C),rounding_n);
    C=intersect(Difm,eF);
    Difm=C;
    nelD=length(Difm);
end

