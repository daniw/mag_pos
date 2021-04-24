% Clean workspace
clc;
clear;
%close all;

% Parameters
WRAP_THRESHOLD  = 2^15;    % Threshold for wraparound correction
WRAP_INTMAX     = 2^16;
RAW_PLOT        = 0;

% Read data
file = 'test_009';
data = dlmread([file '.csv'], ',', [1, 0, inf, 5]);
% Wraparound correction
data(data>WRAP_THRESHOLD) = data(data>WRAP_THRESHOLD)-WRAP_INTMAX;

titles = {'Temperature', 'Flux X', 'Flux Y', 'Flux Z', 'Linear', 'Angular'};

% Raw plot
if RAW_PLOT
    for i=1:6
        figure(i);
        plot(data(:,i), 'LineWidth', 2);
        grid on; grid minor;
        title(['Raw plot ' cell2mat(titles(i))]);
    end;
end;


% Value extraction
temp = data(:,1);
flux_x = data(:,2);
flux_y = data(:,3);
flux_z = data(:,4);
linear = data(:,5);
angular = data(:,6);

plots = [2, 3, 5, 6];

% Plot
figure(100);
for i=plots
    subplot(length(plots), 1, find(plots==i));
    plot(data(:,i), 'LineWidth', 2);
    grid on; grid minor;
    title(cell2mat(titles(i)));
end;

print('-dpng', file);
