function [magnitude,freq] = magnitudeFFT(signal,Ts)
% signal    = input signal
% Ts        = sampling time of input signal [s]

Fs   = 1/Ts;                                    % Sampling frequency   [Hz]    
L    = length(signal);                          % Length of signal
if mod(L,2) ~= 0
    L = L-1;                                    % make the length of the signal even
end
spectrum = fft(signal);
magnitude = abs(spectrum/L);
magnitude = magnitude(1:L/2+1);
magnitude(2:end-1) = 2*magnitude(2:end-1);
freq = Fs/L*(0:L/2);
end