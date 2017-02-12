gcc -fopenmp scaling_fast_transpose.c -lm
./a.out > time.txt
gnuplot plot.gp -persist

