clear all
clc
 
arduino=serialport("/dev/cu.usbserial-1420",921600);
 
fopen(arduino);
 
disp('arduino connected successfully')
x=linspace(1,10^100);

align = fscanf(arduino, '%d');
disp('reading data...')

for i=1:length(x)

	y(i) = 100*(fscanf(arduino, '%d'));
 
    z(i) = 90*(fscanf(arduino, '%d'));

    k(i) = (fscanf(arduino, '%d'));

   
end

disp('making plot..')
figure,
scatter(x,y, 'filled')
hold on
scatter(x,z, 'filled')
hold on
scatter(x,k, 'filled')
hold off
legend ('Heal strike', 'Toe strike', 'Ankle Angle')
disp('done')