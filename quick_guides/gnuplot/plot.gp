set term pngcairo noenhanced size 1300,600
set output "figure.png"
set multiplot layout 1,3
#
set title 'degree distribution' #font ",14"
unset key
set tics scale .3
set mxtics 4
set boxwidth 1
#set logscale y
#set style fill solid
#set xrange [-2:100]
set xlabel "degree"
set ylabel "degree/N"
set xtics 0,25,100
plot 'degree.txt' u 1:2 with boxes title " "
#
set title " "
set logscale y
set xlabel 'degree'
set ylabel 'cumulative distribution'
plot 'cumulative_deg.txt' u 1:2 w p ps 0.5 pt 7  title " "

#
set title " "
set logscale y
set xlabel 'strength'
set ylabel ' '
set xtics 0,0.5,1.5
plot 'cumulative_str.txt' u 1:2 w p ps 0.5 pt 7  title " "

unset multiplot

