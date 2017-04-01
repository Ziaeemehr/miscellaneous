g++ omp_bug1.c -fopenmp
./a.out > 1.txt
rm a.out
g++ omp_bug1fix.c -fopenmp
./a.out > 2.txt
rm a.out
vimdiff 1.txt 2.txt
