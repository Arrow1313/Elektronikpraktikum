#set yrange[-0.00001:0.00001]
#set xrange[-7:1]
#set mxtics 5
#set mytics 5
set xlabel "Spannung/V"
set ylabel "Strom/mA"

#f(x) = m*x+b

#fit f(x) "kreis_1.dat" using 1:2:4 via m,b

set key left top

plot "a2_1.dat" with xyerrorbars title "Durchlassrichtung"#, f(x) title "Regressionsgerade"

set terminal postscript eps enhanced color font 'Helvetica,12'
set output "a2_1.eps"
replot 

!epstopdf a2_1.eps

