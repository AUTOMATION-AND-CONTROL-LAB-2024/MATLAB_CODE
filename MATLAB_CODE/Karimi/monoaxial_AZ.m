%% MONOAXIAL CONTROLLER

%% PARAMETERS
sat = 1.2;
Jxx = 0.055;
disturbance = 0.2;
meas_noise = 0.0001;
Ts = 0.05;
s = tf('s');
Gs = Jxx/s^2;
Gz = c2d(Gs,Ts)
poles = pole(Gz);
zeros = zero(Gz);