clc;
clear;
close all;

Magnet_5x2x2_import;

saturation = 50;

figure(1);
plot(Magnet5x2x2distance.Distance, Magnet5x2x2distance.FluxDensity*1e3, 'LineWidth', 2);
hold on;
l_y_l = [saturation saturation];
l_y_h = [max(Magnet5x2x2distance.FluxDensity) max(Magnet5x2x2distance.FluxDensity)]*1e3;
l_x = [min(Magnet5x2x2distance.Distance) max(Magnet5x2x2distance.Distance)];
l = fill([l_x fliplr(l_x)], [l_y_l fliplr(l_y_h)], 'r');
line(l_x, l_y_l, 'LineWidth', 2, 'Color', 'red');
hold off;
alpha(l, 0.5);
grid on; grid minor;
ylim([0 100]);
ylabel('Flux Density [mT]');
xlabel('Distance [mm]');
title('FEMM simulation 5x2x2mm Magnet');