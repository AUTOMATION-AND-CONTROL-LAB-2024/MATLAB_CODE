%% Main
clear all
close all
clc

% Add the "functions_and_parameters" folder and its subfolders to Matlab path (just for the current Matlab session)
addpath(genpath("libs"));
%% Simulation of the model
Ts_slk      =       0.01;              % sampling time (s)
Tend_slk    =       400;               % simulation time (s) 

prefilter_pole    = 0.7;
%% Quadcopter Parameters  
getQuadcopterParameters();

%% EKF1 Parameters
% getEKF1Parameters();

%% EKF2 Parameters
getEKF2Parameters();

%% EKF rate Parameters
getEKFRateParameters();

%% rotation from IMU-frame to BODY-frame
computeIMUToBodyRotation();

%% PID Camilla Parameters
getPIDParameters();

%% H2 Control Parameters
% getH2ControlParameters();

%% VSC Anna Parameters
% getVSCParameters();

%% Pole Placement Parameters
% getPPController();

