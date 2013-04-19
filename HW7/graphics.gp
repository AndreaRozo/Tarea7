set terminal jpeg
set output 'GraficaR.jpg'
set title "R como función del tiempo"
set xlabel "t [Ks]"
set ylabel "R(t) [1e12 cm]"
plot 'fileOut.txt' using 1:2

set output 'Graficav.jpg'
set title "v como función del tiempo"
set xlabel "t [Ks]"
set ylabel "v(t) [1e12 cm/ 1Ks]"
plot 'fileOut.txt' using 1:3

set output 'GraficaP.jpg'
set title "P como función del tiempo"
set xlabel "t [Ks]"
set ylabel "P(t) [1e29 g / ((1e3 s)^2 * 1e12cm)]"
plot 'fileOut.txt' using 1:4
