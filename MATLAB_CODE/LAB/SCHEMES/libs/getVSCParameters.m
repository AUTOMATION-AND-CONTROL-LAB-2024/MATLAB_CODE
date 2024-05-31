function [] = getVSCParameters()
Ixx         =   0.07;                  %  moment of inertia (kg*m^2)
Ts_slk      =   0.01;
s           =   tf('s');

%% Initial conditions (which correspond to the equilibrium conditions)
x0          = [1;0]*0.01;     % State Equilibrium Vector - Roll angles and rates

%% parameter uncertainty 
epsilon = 13; % più è piccolo, più il transitorio è lento

%% VSC
A   =   [0 1;
        0 0];
B   =   [0;
         1];
C   =   [1/Ixx 0];
D   =   [0];
G   =   C*inv(s*eye(2)-A)*B+D; 

beta1   =   0.3;            % eigenvalue of the system constrained to slide along s=0 
beta_t  =   [beta1 1];
alpha_t =   beta_t*A;
gamma   =   beta1/C(1,1);
r       =   1;
t_reach =   1;
y_des   =   0.5;
W       =   0.2;
q       =   (abs(beta1*x0(1,1)+x0(1,1)-gamma*y_des)/t_reach)+W;

%% high frequency input switching
% Building the enlarged system because of the introduction of the integrator

F       =   [A B;
            zeros(1,2) zeros(1,1)];
G       =   [0;0;1];
H       =   [C 0];

beta_t_en   =   [1 2 1];  % (lambda+0.5)^2 -> eignevalues of the system along s=0
alpha_t_en  =   beta_t_en*F;
gamma_en    =   beta_t_en(1,1)/H(1,1);
q_en        =   (abs(-gamma_en*y_des)/t_reach)+W;


%% Filter

filter = 1/(1+s/20);
filter_d = c2d(filter, Ts_slk);
%% To Workspace
assignin('base', 'epsilon', epsilon);
assignin('base', 'beta1', beta1);
assignin('base', 'beta_t', beta_t);
assignin('base', 'alpha_t', alpha_t);
assignin('base', 'gamma', gamma);
assignin('base', 'r', r);
assignin('base', 'q', q);
assignin('base', 'beta_t_en', beta_t_en);
assignin('base', 'alpha_t_en', alpha_t_en)
assignin('base', 'gamma_en', gamma_en);
assignin('base', 'q_en', q_en);
assignin('base', 'filter_d', filter_d);
