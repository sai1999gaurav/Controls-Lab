Mp = 0.027;
lp = 0.153;
Lp = 0.191;
r = 0.08260;
Jm = 3E-5;
Marm = 0.028;
g = 9.810;
Jeq = 1.23E-4;
Jp = 1.1E-4;
Beq = 0;
Bp = 0;
Rm = 3.3;
Kt = 0.02797;
Km = 0.02797;

A32 = r*Mp^2*lp^2*g/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2);
A33 = -Kt*Km*(Jp+Mp*lp^2)/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2)/Rm;
A42 = Mp*lp*g*(Jeq+Mp*r^2)/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2);
A43 = -Mp*lp*Kt*r*Km/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2)/Rm;

B3 = Kt*(Jp+Mp*lp^2)/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2)/Rm;
B4 = Mp*lp*Kt*r/(Jp*Jeq+Mp*lp^2*Jeq+Jp*Mp*r^2)/Rm;

A = [0 0 1 0; 0 0 0 1; 0 A32 A33 0; 0 A42 A43 0];
B = [0; 0; B3; B4];

%disp(A);
%disp(B);
q1 = 1;
q2 = 1;
q3 = 1;
q4 = 1;
Q = diag([q1 q2 q3 q4]);

R = 1;
K = lqr(A, B, Q, R);
disp(-K);
