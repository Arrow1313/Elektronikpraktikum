set yrange[-0.8:6]
#set xrange[0:0.9]
#set mxtics 5
#set mytics 5
set xlabel "Eingangsspannung/V"
set ylabel "Ausgangsspannung/V"

#f(x) = m*x+b

#fit f(x) "kreis_1.dat" using 1:2:4 via m,b

set key left top

plot "3_4_min_v.dat" with xyerrorbars title "Messdaten"#, f(x) title "Regressionsgerade"

set terminal postscript eps enhanced color font 'Helvetica,12'
set output "3_4_min_v.eps"
replot 

!epstopdf 3_4_min_v.eps

