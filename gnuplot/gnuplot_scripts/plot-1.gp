#! /usr/bin/gnuplot

set terminal postscript eps enhanced
set output "plot-1.eps"
set title "plot-1"

set xrange[-pi:pi]
set yrange[-2:2]

plot sin(x) with line lc 1
