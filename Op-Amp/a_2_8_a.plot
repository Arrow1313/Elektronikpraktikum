#set yrange[-0.8:100]
set xrange[-5:105]
#set mxtics 5
#set mytics 5
set xlabel "Intaensitaet"
set ylabel "U0/V"

#f(x) = m*x+b

#fit f(x) "a_2_8_a.dat" using 1:2:4 via m,b

set key left top

plot "a_2_8_a.dat" with xyerrorbars title "Messdaten"#, f(x) title "Regressionsgerade"

set terminal postscript eps enhanced color font 'Helvetica,12'
set output "a_2_8_a.eps"
replot 

!epstopdf a_2_8_a.eps

