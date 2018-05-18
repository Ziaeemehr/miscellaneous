#! /usr/bin/gnuplot
set terminal png
set output 'file.png'

plot sin(x)

set terminal x11 persist
set output
replot


# set terminal push
# set terminal pngcairo
# set output 'file.png'
# plot sin(x)
# set terminal pop
# set output
# replot