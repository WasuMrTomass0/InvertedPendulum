clear all;
close all;

%% Wy³uskanie z równa´n uwiklanych pochodnych po pr²edko{\’s}ci wózka i wahad³a
syms x1 x2 dx2 x3 x4 dx4 M m b l I g cp F
eq1 = (M+m)*dx2 + b*x2 == -m*l*dx4*cos(x3) + m*l*x4^2*sin(x3) + F;
eq2 = (I+m*l^2)*dx4 == m*g*l*sin(x3) - m*l*dx2*cos(x3) -cp*x4;
s = solve(eq1, eq2, dx2, dx4);
sdx2 = s.dx2; % przyspieszenie x
sdx4 = s.dx4; % przyspieszenia theta

%% Równania stanu
dx1 = x2;
dx2 = (I*b*x2 - b*l^2*m*x2 + l^3*m^2*x4^2*sin(x3) - g*l^2*m^2*cos(x3)*sin(x3) + I*l*m*x4^2*sin(x3) + cp*l*m*x4*cos(x3))/(I*m + I*M + l^2*m^2 - l^2*m^2*cos(x3)^2 + M*l^2*m);
dx3 = x4;
dx4 = -(M*cp*x4 + cp*m*x4 - g*l*m^2*sin(x3) + l^2*m^2*x4^2*cos(x3)*sin(x3) - M*g*l*m*sin(x3) - b*l*m*x2*cos(x3))/(I*m + I*M + l^2*m^2 - l^2*m^2*cos(x3)^2 + M*l^2*m);
DX = [dx1;dx2;dx3;dx4];
B = [0; (I +l^2*m)/(I*m + I*M + l^2*m^2 - l^2*m^2*cos(x3)^2 + M*l^2*m); 0; (l*m)/(I*m + I*M + l^2*m^2 - l^2*m^2*cos(x3)^2 + M*l^2*m)];
b_lin = [0; (I +l^2*m)/(I*m + I*M + l^2*m^2 - l^2*m^2 + M*l^2*m); 0; (l*m)/(I*m + I*M + l^2*m^2 - l^2*m^2 + M*l^2*m)];

%% Linerazycja w punkcie pracy (0,0,0,0):
f = [x2, dx2, x4, dx4];
J = jacobian(f, [x1, x2, x3, x4]); % Jakobian - macierz pochodnych cz ² astkowych
%% Podstawienie zmiennych:
J_val = subs(J,{x1, x2, x3, x4, M, m, b, l, I, g, cp},{0, 0, 0, 0, 0.548, 0.048, 0.28, 0.2097, 0.0018, 9.81, 0});
A = eval(J_val);
B_temp = subs(b_lin, {I, l, M, m,}, {0.0018, 0.2097, 0.548, 0.048});
B = eval(B_temp);
C = [1 0 0 0; 0 0 1 0];
D = [0; 0];

%% Model State-Space
states = {'x' 'x_dot' 'phi' 'phi_dot'};
inputs = {'u'};
outputs = {'x'; 'phi'};
sys_ss = ss(A,B,C,D,'statename',states,'inputname',inputs,'outputname',outputs);
eig(A);

%% LQR
co = ctrb(sys_ss);
controllability = rank(co) % sterowalny jeÿzeli rz ² ad macierzy == 4

%% Pierwszy regulator LQR, który lepiej stabilizuje wahad³o u góry
Q = [5 0 0 0;
0 0 0 0;
0 0 600 0;
0 0 0 0];
R = 1;
[K,S,e] = lqr(sys_ss,Q,R);
An = A-B*K;
Bn = B;
Cn = C;
Dn = D;
init;
K_stab = [-K(1) -K(2) K(3)/3 K(4)/3]

%% Drugi regulator, który lepiej utrzymuje wózek na srodku szyny
Q = [15 0 0 0;
0 0 0 0;
0 0 600 0;
0 0 0 0];
[K,S,e] = lqr(sys_ss,Q,R);
K_later = [-K(1) -K(2) K(3)/3 K(4)/3]