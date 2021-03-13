m = 1;
l = 1;
Jp = 1;
g = 9.81;
p1 = 1;
fc =1;
p2 = 1;
fp = 1;
encoder_freq = 100; %[verify]

a1 = Jp / (m * l);
a2 = 1 / l;
b = a1 * a2;
k1= p1 / (m * l);
k2 = (fc - p2) / (m * l);
k3 = fp / (m*l);