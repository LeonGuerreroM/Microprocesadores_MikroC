clc
clear all
close all

n1=0:7;
N1=8;
y1=127+127*sin(2*pi*n1/N1)

figure(1)
plot(n1,y1)

n2=0:15;
N2=16;
y2=127+127*sin(2*pi*n2/N2)

figure(2)
plot(n2,y2)

x1 = 127+127*sawtooth(2*pi*n1/N1)

figure(3)
plot(n1,x1)

x2 = 127+127*sawtooth(2*pi*n2/N2)

figure(4)
plot(n2,x2)

z1= 127+127*square(2*pi*n1/N1)

figure(5)
plot(n1,z1)

z2= 127+127*square(2*pi*n2/N2)

figure(6)
plot(n2,z2)

t1=abs(254*(sin(pi*n1/N1)))

figure(7)
plot(n1,t1)



t2=abs(254*(sin(pi*n2/N2)))

figure(8)
plot(n2,t2)
