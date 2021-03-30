% % % % Stale:
g = 9.8101;
m_c = 0.503 + 0.045;
m_p = 2 * (20.5 + 11)/1000;  
% % % % 2 * 0.055; wg napisu
f_c = 0.5;
f_p = 6.65e-5;
% % % % 

% dlugosc wahadla xD aby policzyc j_p
% Wahadlo:
% odwaznik  11   g   mosiezny
% pret      20,5 g   aluminium

m_pw = 2 * 11 / 1000;
m_ps = 2 * 20.5 / 1000;
r_c = 5.5 / 1000;
l_c = 19 / 1000;
r_p = 3 / 1000;
l_p = 43 / 100;
l_c0 = 39.6 / 100;
l_p0 = 18.1 / 100;
L = l_p0;

j_p = 1/12 * m_pw * l_c ^ 2 ...
    + 1/4 * m_pw * r_c ^ 2 ...
    + m_pw * l_c0 ^ 2 ...
    + 1/12 * m_ps * l_p ^ 2 ...
    + 1/4 * m_pw * r_p ^ 2 ...
    + m_ps * l_p0 ^ 2;


% % % % Wartosci wyliczane:
m = m_c + m_p;
mL = m * L;

a_1 = j_p / (m * L);
a_2 = 1 / L;
b = a_1 * a_2;
k_1 = p_1 / (m * L);
k_2 = (f_c - p_2) / (m * L);
k_3 = f_p / ( m * L);

p_1 = 9.4;       % N
p_2 = -0.548;    % N * s / m 
