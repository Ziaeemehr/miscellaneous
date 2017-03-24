omp_get_thread_num() - get the thread rank in a parallel region (0- omp_get_num_threads() -1)
omp_set_num_threads(nthreads) - set the number of threads used in a parallel region
omp_get_num_threads() - get the number of threads used in a parallel region

// How to compile
g++ -o omp_helloc -fopenmp omp_hello.cpp
export OMP_NUM_THREADS=2
./omp_helloc

#include<omp.h>

#pragma omp parallel private(nthreads,tid) num_threads(4)

int nProcessors=omp_get_max_threads();
omp_set_num_threads(nProcessors);

// LOOP with No Data Dependencies
#pragma omp parallel for private(temp) shared(n,a,b,c)
{
   for(i=1; i<=n; i++){
      temp = 2.0*a[i];
      a[i] = temp;
      b[i] = c[i]/temp;
   }
}