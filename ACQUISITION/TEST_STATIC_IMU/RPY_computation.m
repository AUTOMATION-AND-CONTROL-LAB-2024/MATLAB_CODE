
function [RPY_meas,method_ps]   = RPY_computation(a_b,mf_b,mf)
% description:
% - a_b             = measured linear acceleration in body-frame
% - w_b             = measured angular velocity in body-frame
% - mf_b            = measured magnetic field in body-frame
% - mf              = measured magnetic field in body-inertia
% - a_b_disturbe    = linear velocity measurement-noise
% - w_b_disturbe    = angular velocity measurement-noise
% - mf_b_disturbe   = magnetic field measurement-noise

% -------------------------------------------------------------------------------------------
% observation: the following computation works only if the angles
% phi,theta,psy are withing angles (-pi/2,+pi/2) (this is an open set, pi/2 is excluded)
% -------------------------------------------------------------------------------------------

a_b = -1*a_b;       % need to adjust the sign to use atan2() function correctly
mf_u = mf(3,1);     % magnetic field in up direction (z-dir in inertia frame)

% phi computation
ph_meas = atan2(a_b(2), a_b(3));
sph = sin(ph_meas);
cph = cos(ph_meas);

% theta computation
th_meas = atan2(-a_b(1), (a_b(2)*sph + a_b(3)*cph));
sth = sin(th_meas);
cth = cos(th_meas);

% psi computation
if abs(sin(th_meas)) > 0.01  % sin(th) != 0 
    method_ps = 1;
    ps_meas_numerator   = (sth*cph*mf_b(2) - sth*sph*mf_b(3))/(-sth);       % don't modify
    ps_meas_denominator = (-sph*mf_b(2) - cph*mf_b(3) + cth*mf_u)/(-sth);   % don't modify
    ps_meas = atan2(ps_meas_numerator, ps_meas_denominator);
else                        % sin(th) == 0
    method_ps = 2;
    ps_meas_numerator   = (mf_b(2) - cth*sph*mf_u)*(-cth);
    ps_meas_denominator = cph*mf_b(1);
    ps_meas = atan2(ps_meas_numerator, ps_meas_denominator);
end
RPY_meas = [ph_meas;th_meas;ps_meas];