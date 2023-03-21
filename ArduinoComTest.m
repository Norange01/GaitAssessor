clear all
clc
 
arduino=serialport("/dev/cu.usbserial-1410",9600);
 
fopen(arduino);
 
x=linspace(1,100);
y = zeros(1,100);
   
for i=1:length(x)
	y(1,i) = fscanf(arduino, '%d');
end
	
fclose(arduino);
disp('making plot..')
plot(x,y);