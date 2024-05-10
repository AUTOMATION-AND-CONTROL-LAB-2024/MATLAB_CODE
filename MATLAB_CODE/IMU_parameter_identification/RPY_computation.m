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

% phi computation
ph_meas = atan2(a_b(2), a_b(3));
sph = sin(ph_meas);
cph = cos(ph_meas);

% theta computation
th_meas = atan2(-a_b(1), (a_b(2)*sph + a_b(3)*cph));
sth = sin(th_meas);
cth = cos(th_meas);

% psi computation
ps_meas_num   = mf_b(3)*sph - mf_b(2)*cph;
ps_meas_den   = mf_b(1)*cth + mf_b(2)*sth*sph + mf_b(3)*sth*cph;
ps_meas = atan2(ps_meas_num, ps_meas_den);

RPY_meas = [ph_meas;th_meas;ps_meas];