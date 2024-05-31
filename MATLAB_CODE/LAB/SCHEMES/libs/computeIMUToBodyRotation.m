function [] = computeIMUToBodyRotation()
%% rotation from IMU-frame to BODY-frame
angleZ = pi/4;
Rz = [cos(angleZ) -sin(angleZ)   0;
      sin(angleZ) cos(angleZ)    0;
             0       0           1;];

clear angleZ;

%% To Workspace
assignin('base', 'Rz', Rz);
end