%syms a mi fc l g fp j0 x1 x2 x3 x4 u
syms x1 x2 x3 x4 u
M = 0.872; %masa wozka i wahadla
fp = 6.65 * 10^-5; %wsp. tarcia w lozysku wahadla
fc = 0.5; %wsp. tarcia w lozyskach wozka
l = 0.107; %odleglosc srodka masy ukladu od osi ukladu
j0 = 0.00282; %moment bezwladnosci wahadla
g = 9.81;
mi = l*M;
a = l^2 + (j0/M);
dx1 = x3;
dx2 = x4;
dx3 = (a*(u - (mi*(x4^2)*sin(x2)) - fc*x3) + l*cos(x2)*(mi*g*sin(x2) - fp*x4)) / (j0 - mi*l*(cos(x2))^2);
dx4 = (l*cos(x2)*(u-mi*(x4^2)*sin(x2) - fc*x3) + mi*g*sin(x2) - fp*x4) / (j0 - mi*l*(cos(x2))^2);

B = [0; 0; a/(j0 - mi*l*(cos(x2))^2); l*cos(x2)/(j0 - mi*l*(cos(x2))^2)];

b_lin = [0; 0; a/(j0 - mi*l); l/(j0 - mi*l)];


f = [x3, dx3, x4, dx4];
J = jacobian(f, [x1, x2, x3, x4])
M = 0.872; %masa wozka i wahadla
fp = 6.65 * 10^-5; %wsp. tarcia w lozysku wahadla
fc = 0.5; %wsp. tarcia w lozyskach wozka
l = 0.107; %odleglosc srodka masy ukladu od osi ukladu
j0 = 0.00282; %moment bezwladnosci wahadla
g = 9.81;
mi = l*M;
a = l^2 + (j0/M);
J_val = subs(J, {x1, x2, x3, x4, M, fp, fc, l, j0, g, mi, a}, {0, 0, 0, 0, 0.872, 6.65 * 10^-5, 0.5, 0.107, 0.00282, 9.81, 0.0933, 0.0147})

A = eval(J_val);

B_val = subs(b_lin, {a, j0, mi, l}, {0.014682944954128, 0.0028, 0.0933, 0.1070})

B = eval(B_val)

C = [1 0 0 0; 0 1 0 0];
D = [0; 0];

sys = ss(A,B,C,D);

eig(A)


controllability = rank(ctrb(sys))


% Pierwszy regulator LQR, który lepiej stabilizuje wahad³o u góry
Q = [5 0 0 0;
0 0 0 0;
0 0 600 0;
0 0 0 0];
R = 1;
[K,S,e] = lqr(sys,Q,R)
An = A-B*K;
Bn = B;
Cn = C;
Dn = D;


K_stab = [-K(1) -K(2) K(3)/3 K(4)/3]
% Drugi regulator, który lepiej utrzymuje wózek na {\’s}rodku szyny
Q = [15 0 0 0;
0 0 0 0;
0 0 600 0;
0 0 0 0];
[K,S,e] = lqr(sys,Q,R)
K_later = [-K(1) -K(2) K(3)/3 K(4)/3]





