function [magnitude,freq] = signalFFT(signal,Ts)
% signal    = input signal
% Ts        = sampling time of input signal [s]
Fs   = 1/Ts;            % Sampling frequency   [Hz]    
L    = length(signal);  % Length of signal
if mod(L,2) ~= 0
    L = L-1;
end

signal = lowpass(signal,Fs/2.01,Fs);
spectrum = fft(signal);
magnitude = abs(spectrum/L);
magnitude = magnitude(1:L/2+1);
magnitude(2:end-1) = 2*magnitude(2:end-1);

freq = Fs/L*(0:L/2);
end