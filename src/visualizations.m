% signals(1) - sterowanie
% signals(2) - wychylenie wahadla
% signals(3) - predkosc wahadla
% signals(4) - polozenie wozka
% signals(5) - predkosc wozka

% data = load("data/wplyw_pchniecia_wozka_na_bujanie_wahadla_w_lewo.mat");
data = load("data/bujanie_wahadla_trzymajac_reka_wozek.mat");
mass = 0.611; % kg

figure(1)
plot(data.P1_Data.time, data.P1_Data.signals(2).values)
grid on

%% Okres drgan oraz tarcie wahadla
data = load("data/bujanie_wahadla_trzymajac_reka_wozek.mat");
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

num_of_swings = 28;
t1 = 212.94; t2 = 248.79; t = (t2 - t1) / num_of_swings;

figure(2); clf(2); hold on; grid on; 
xlim([210 250]); xlabel("Czas [s]"); ylabel("Wychylenie [rad]");
title(strcat("Okres wahadla = ", num2str(t), " s"));

plot(time, pos); 
scatter([t1; t2], [0; 0], 'r*');
scatter(transpose(t1:t:t2), zeros(num_of_swings + 1,1), 'b.');


% figure(4); clf(4); hold on; grid on; 
% plot(time, vel);
% % Spsob nr 1 : Przyblizenie prosta - 2 punkty
% plot([439.17, 453.54], [5.21553, 2.76117], 'm');
% acceleration = (2.76117 - 5.21553) / (453.54 - 439.17);  % m / s^2
% friction = abs(mass * acceleration); % N
% title(strcat("Tarcie wahadla = ", num2str(friction), " N"))
% legend(["Velocity", "Method 1"]);

%% Tarcie wozka
% LEWO
data = load("data/wplyw_pchniecia_wozka_na_bujanie_wahadla_w_lewo.mat");
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
disp(strcat("Ruch w lewo. Tarcie wozka = ", num2str(friction1), " N -> Method 1"))
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

% PRAWO
data = load("data/wplyw_pchniecia_wozka_na_bujanie_wahadla.mat");
time = data.P1_Data.time;
pos = data.P1_Data.signals(4).values;
vel = data.P1_Data.signals(5).values;
figure(31); clf(31); hold on; grid on; 
plot(time, pos); plot(time, vel); xlim([282, 284]);
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % Sposob nr 1: Przyblizenie liniowe - 2 punkty
% Indexes: 261 -> 370
plot([282.93, 283.62], [1.15818, 0], 'm')
% time:     start: 438.7   s     stop: 439.78   m/s
% velocity: start: -1.9341 s     stop: 0        m/s
acceleration = 1.15818 / (283.62 - 282.93);     % m / s^2
friction1 = mass * acceleration;               % N
disp(strcat("Ruch w lewo. Tarcie wozka = ", num2str(friction1), " N -> Method 1"))
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % Sposob nr 2: Przyblizenie liniowe - 3 punkty, 2 proste
% Indexes: 261 -> 301, 301 -> 370
% plot([438.7, 439.15],  [-1.9341,   -0.650404], 'b')
% plot([439.15, 439.78], [-0.650404, 0.0057053], 'b')
plot([282.93, 283.3],  [1.15818, 0.365139], 'k')
plot([283.3, 283.62], [0.365139, 0], 'k')
% time:     start: 438.7   s     stop: 439.78   m/s
% velocity: start: -1.9341 s     stop: 0        m/s
acceleration1 = (-0.741689 + 1.9341) / (283.3 - 282.93);     % m / s^2
acceleration2 = (0.365139) / (283.62 - 283.3);  % m / s^2
friction2 = mass * (acceleration1 + acceleration2) / 2; % N
disp(strcat("Friction = ", num2str(friction2), " N -> Method 2"))
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
legend(["Position", "Velocity", "Method 1", "Method 2"])
title(strcat("Friction_{1} = ", num2str(friction1),...
    " N,      Friction_{2} = ", num2str(friction2), " N"))

%% Bujanie a ruch wozka
data = load("data/wplyw_bujania_na_ruch_wozka.mat");
time = data.P1_Data.time;
pend_pos = data.P1_Data.signals(2).values;
troll_pos = data.P1_Data.signals(4).values;
troll_vel = data.P1_Data.signals(5).values;

pend_pos(1) = 0;
for i=2:size(pend_pos, 1)
    if pend_pos(i) > 0
        pend_pos(i) = pend_pos(i) - pi;
    elseif pend_pos(i) < 0
        pend_pos(i) = pend_pos(i) + pi;
    end
    vel(i) = (pend_pos(i) - pend_pos(i-1)) / (time(i) - time(i-1));
end

figure(3); clf(3); hold on; grid on; r=2;c=1;n=1; 
subplot(r,c,n); n=n+1; plot(time, pend_pos);  grid on; ylim([-pi pi]); xlim([130 185]);
xlabel("Czas [s]"); ylabel("Wychylenie [rad]"); title("Wahadło");

subplot(r,c,n); n=n+1; plot(time, troll_vel); grid on; ylim([-0.1 0.1]); xlim([130 185]);
xlabel("Czas [s]"); ylabel("Prędkość"); title("Wózek");








