
%% RUN 1
time_stamp = xlsread('data.xlsx', 'Sheet2', 'E1:E90');
angle = xlsread('data.xlsx', 'Sheet2', 'F1:F90');
ref_angle = 240 - angle;
reference = 180.*ones(90,1);
rise_t1 = 183.6.*ones(90,1);
rise_t2 = 176.4.*ones(90,1);
ten_per = 18.*ones(90,1);
ninety_per = 162.*ones(90,1);
plot(time_stamp,ref_angle,'linewidth', 2);
hold on;
plot(time_stamp, reference, 'linewidth',1);
hold on;
plot(time_stamp, ten_per, 'linewidth',1);
hold on;
plot(time_stamp, ninety_per, 'linewidth',1);
hold on;
plot(time_stamp, rise_t1, 'linewidth',1);
hold on;
plot(time_stamp, rise_t2, 'linewidth',1);
hold on;
title('Relative Angle vs Time');
xlabel('Time (in ms)');
ylabel('Relative Angle (in degrees)');
legend('Angle','180', '180*10%', '180*90%', '180+2%', '180-2%')
%% RUN2
time_stamp = xlsread('data.xlsx', 'Sheet4', 'B1:B83');
angle = xlsread('data.xlsx', 'Sheet4', 'C1:C83');
ref_angle = angle-50;
a = size(time_stamp, 1);
reference = 180.*ones(a,1);
rise_t1 = 183.6.*ones(a,1);
rise_t2 = 176.4.*ones(a,1);
ten_per = 18.*ones(a,1);
ninety_per = 162.*ones(a,1);
plot(time_stamp,ref_angle,'linewidth', 2);
hold on;
plot(time_stamp, reference, 'linewidth',1);
hold on;
plot(time_stamp, ten_per, 'linewidth',1);
hold on;
plot(time_stamp, ninety_per, 'linewidth',1);
hold on;
plot(time_stamp, rise_t1, 'linewidth',1);
hold on;
plot(time_stamp, rise_t2, 'linewidth',1);
hold on;
title('Relative Angle vs Time');
xlabel('Time (in ms)');
ylabel('Relative Angle (in degrees)');
legend('Angle','180', '180*10%', '180*90%', '180+2%', '180-2%')

%% RUN3
time_stamp = xlsread('data.xlsx', 'Sheet5', 'B1:B95');
angle = xlsread('data.xlsx', 'Sheet5', 'C1:C95');
ref_angle = 210-angle;
a = size(time_stamp, 1);
reference = 180.*ones(a,1);
rise_t1 = 183.6.*ones(a,1);
rise_t2 = 176.4.*ones(a,1);
ten_per = 18.*ones(a,1);
ninety_per = 162.*ones(a,1);
plot(time_stamp,ref_angle,'linewidth', 2);
hold on;
plot(time_stamp, reference, 'linewidth',1);
hold on;
plot(time_stamp, ten_per, 'linewidth',1);
hold on;
plot(time_stamp, ninety_per, 'linewidth',1);
hold on;
plot(time_stamp, rise_t1, 'linewidth',1);
hold on;
plot(time_stamp, rise_t2, 'linewidth',1);
hold on;
title('Relative Angle vs Time');
xlabel('Time (in ms)');
ylabel('Relative Angle (in degrees)');
legend('Angle','180', '180*10%', '180*90%', '180+2%', '180-2%')