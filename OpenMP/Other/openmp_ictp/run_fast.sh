gcc -fopenmp fast_openmp.c 
./a.out > time.txt
echo 'plot "time.txt" u 1:2 w l title " " , "" u 1:2 w p  ' | gnuplot -persist

