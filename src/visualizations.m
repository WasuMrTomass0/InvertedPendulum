% signals(1) - sterowanie
% signals(2) - wychylenie wahadla
% signals(3) - predkosc wahadla
% signals(4) - polozenie wozka
% signals(5) - predkosc wozka

data = load("data/wplyw_pchniecia_wozka_na_bujanie_wahadla_w_lewo.mat");
mass = 0.611; % kg

% figure(1)
% plot(data.P1_Data.time, data.P1_Data.signals(2).values)
% grid on

%% Okres drgan oraz tarcie wahadla
time = data.P1_Data.time;
pos = data.P1_Data.signals(2).values;
vel = zeros(size(pos, 1), 1);
pos(1) = 0;
for i=2:size(pos, 1)
    if pos(i) > 0
        pos(i) = pos(i) - pi;
    elseif pos(i) < 0
        pos(i) = pos(i) + pi;
    end
    vel(i) = (pos(i) - pos(i-1)) / (time(i) - time(i-1));
end
t1 = 439.14; t2 = 453.53; t = (t2 - t1) / 11;
figure(2); clf(2); hold on; grid on; 
plot(time, pos); 
scatter([t1; t2], [0; 0], 'r*');
scatter(transpose(t1:t:t2), zeros(12,1), 'b.');
title(strcat("Okres drgań wahadla = ", num2str(t), " s"));

figure(4); clf(4); hold on; grid on; 
plot(time, vel);
% Spsob nr 1 : Przyblizenie prosta - 2 punkty
plot([439.17, 453.54], [5.21553, 2.76117], 'm');
acceleration = (2.76117 - 5.21553) / (453.54 - 439.17);  % m / s^2
friction = abs(mass * acceleration); % N
title(strcat("Tarcie wahadla = ", num2str(friction), " N"))
legend(["Velocity", "Method 1"]);

%% Tarcie wozka
time = data.P1_Data.time;
pos = data.P1_Data.signals(4).values;
vel = data.P1_Data.signals(5).values;
figure(3); clf(3); hold on; grid on; 
plot(time, pos); plot(time, vel); xlim([438, 440]);
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % Sposob nr 1: Przyblizenie liniowe - 2 punkty
% Indexes: 261 -> 370
plot([438.7, 439.78], [-1.9341, 0.0057053], 'm')
% time:     start: 438.7   s     stop: 439.78   m/s
% velocity: start: -1.9341 s     stop: 0        m/s
acceleration = 1.9341 / (439.78 - 438.7);     % m / s^2
friction1 = mass * acceleration;               % N
disp(strcat("Tarcie wozka = ", num2str(friction1), " N -> Method 1"))
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % Sposob nr 2: Przyblizenie liniowe - 3 punkty, 2 proste
% Indexes: 261 -> 301, 301 -> 370
% plot([438.7, 439.15],  [-1.9341,   -0.650404], 'b')
% plot([439.15, 439.78], [-0.650404, 0.0057053], 'b')
plot([438.7, 439.09],  [-1.9341,   -0.741689], 'k')
plot([439.09, 439.78], [-0.741689, 0.0057053], 'k')
% time:     start: 438.7   s     stop: 439.78   m/s
% velocity: start: -1.9341 s     stop: 0        m/s
acceleration1 = (-0.741689 + 1.9341) / (439.09 - 438.7);     % m / s^2
acceleration2 = (0.0057053 + 0.741689) / (439.78 - 439.09);  % m / s^2
friction2 = mass * (acceleration1 + acceleration2) / 2; % N
disp(strcat("Friction = ", num2str(friction2), " N -> Method 2"))
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
legend(["Position", "Velocity", "Method 1", "Method 2"])
title(strcat("Friction_{1} = ", num2str(friction1),...
    " N,      Friction_{2} = ", num2str(friction2), " N"))

