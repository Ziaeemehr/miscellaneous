for i in 1 2 4 8 16
do
    g++ -o jacobi_opm jacobi_opm.cpp -fopenmp
    set OMP_NUM_THREADS=${i}
    ./jacobi_opm 128  100 5 5 > omp${i}.txt
    ./jacobi_opm 256  100 5 5 >> omp${i}.txt
    ./jacobi_opm 1024 100 5 5 >> omp${i}.txt
    ./jacobi_opm 4096 100 5 5 >> omp${i}.txt
    rm jacobi_opm
done
gnuplot plot.gp
display scaling.png
