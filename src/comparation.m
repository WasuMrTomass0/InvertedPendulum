%% Wahadło - mały kąt - model
data = load("data/Wahadlo_MalyKat.mat");
% data.time - czas symulacji
% data.val  - kąt wychylenia
data.val = data.val - pi;
% Wychylenie dla pi/5 - model utworzony na zasadzie:
% 0 - Wahadlo u góry
% +pi, -pi - wahadło u dołu
figure(3); clf(3); hold on; grid on;
plot(data.time, data.val); xlim([0 60]); ylim([-1, 1])
xlabel("Czas [s]"); ylabel("Wychylenie [rad]"); title("Wahadło - mały kąt - model");
% okresow = 12;
% czas = 18.17 - 0.08;
% jeden_okres = czas / okresow;  % = 1.5075
% okresow = 30;
% czas = 45.24 - 0.08;
% jeden_okres = czas / okresow;  % = 1.5053  
%% Wahadło - duży kąt - model
data = load("data/Wahadlo_DuzyKat.mat");
% data.time - czas symulacji
% data.val  - kąt wychylenia
data.val = data.val - pi;
% Wychylenie dla 0.1 - model utworzony na zasadzie:
% 0 - Wahadlo u góry
% +pi, -pi - wahadło u dołu
figure(2); clf(2); hold on; grid on;
plot(data.time, data.val); xlim([0 8clc0]);
xlabel("Czas [s]"); ylabel("Wychylenie [rad]"); title("Wahadło - duży kąt - model");
% okresow = 12;
% czas = 21.07 - 0.15;
% jeden_okres = czas / okresow;  % = 1.7433
% okresow = 30;
% czas = 48.11 - 0.15;
% jeden_okres = czas / okresow;  % = 1.5987