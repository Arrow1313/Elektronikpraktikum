set yrange[-0.8:100]
set xrange[0:0.9]
#set mxtics 5
#set mytics 5
set xlabel "Spannung/V"
set ylabel "Strom/mA"

#f(x) = m*x+b

#fit f(x) "kreis_1.dat" using 1:2:4 via m,b

set key left top

plot "a1_1.dat" with xyerrorbars title "Messdaten"#, f(x) title "Regressionsgerade"

set terminal postscript eps enhanced color font 'Helvetica,12'
set output "a1_1.eps"
replot 

!epstopdf a1_1.eps

