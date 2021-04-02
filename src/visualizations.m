% signals(1) - sterowanie
% signals(2) - wychylenie wahadla
% signals(3) - predkosc wahadla
% signals(4) - polozenie wozka
% signals(5) - predkosc wozka

data = load("data/wplyw_pchniecia_wozka_na_bujanie_wahadla_w_lewo.mat");

plot(data.P1_Data.time, data.P1_Data.signals(5).values)
grid on