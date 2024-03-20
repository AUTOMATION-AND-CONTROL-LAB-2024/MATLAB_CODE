function [mean] = mean(signal)
% compute the mean of the signal in input
mean = sum(signal)/length(signal);
end

