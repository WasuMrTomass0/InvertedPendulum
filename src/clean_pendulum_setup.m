clear all;

M = 0.503 + 0.045;  % masa wozka
f_c = 1.0942;  %0.5;          % tarcie wozka
f_p = 0.10436; %6.65e-5;      % tarcie rotacyjne wahadla

m_pw = 2 * 11 / 1000;
m_ps = 2 * 20.5 / 1000;
r_c = 5.5 / 1000;
l_c = 19 / 1000;
r_p = 3 / 1000;
l_p = 43 / 100;
l_c0 = 39.6 / 100;
l_p0 = 18.1 / 100;
I = 1/12 * m_pw * l_c ^ 2 ...
    + 1/4 * m_pw * r_c ^ 2 ...
    + m_pw * l_c0 ^ 2 ...
    + 1/12 * m_ps * l_p ^ 2 ...
    + 1/4 * m_pw * r_p ^ 2 ...
    + m_ps * l_p0 ^ 2;

L = 0.256;          % odleglosc srodka masy od osi obrotu
m = m_pw + m_ps;    % calkowita masa wahadla
g = 9.81;


% Pomiary poczatkowe:
% Okres 
% T = 1.471[s]
% Czas wytlumienia z maksymalnego polozenia
% t_w = 201[s]