#set yrange["Zahl":"Zahl"]
#set xrange["Zahl":"Zahl"]

set xlabel "U_GS/V" #achsenbeschriftung
set ylabel "I_S/mA"

#set mxtics 5 #nicht beschriftete striche an den achsen
#set mytics 5
#set ytics 1 #beschriftete striche an den achsen
#set xtics 1

#set key left top #position der legende

#set style fill solid border 3 #fillstyle für z.b. ein histogramm
#binwidth=0.08 #breite der bins beim histogramm
#set boxwidth 0.5*binwidth absolute #breite der säulen im vergleich zu den bins
#bin(x,width)=width*floor(x/width) + binwidth/2.0 #funktion für bins
#plot "Messung.dat" u (bin($1,binwidth)):(1.0) notitle smooth freq with boxes #histogramm plotten

#set grid y #horizontales gitter
#set grid x #vertikales gitter

#set sample 10000 #bessere auflösung

#f(x) = m*x+b #funktionen definieren
#fit f(x) "a_4.dat" using 1:2:4 via m,b #funktionen fitten

plot "a_4.dat" with xyerrorbars title "Messdaten"#, f(x) title "Regressionsgerade"#, "Beispiel2.dat" smooth csplines title "Messdaten mit csplines" #plotten von messdaten, regression, und csplines

set terminal postscript eps enhanced color font 'Helvetica,12' #ausgabeformat
set output "a_4.eps" #name des dokuments
replot #dokument plotten

!epstopdf a_4.eps #eps in pdf umwandeln


#A(x) = 2*(0.5+atan(x)/pi) #eingeschränkte funktion
#f(x) = A(a)*cos(x)+c #amplitude beschränken
