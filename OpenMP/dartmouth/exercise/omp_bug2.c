/******************************************************************************
* FILE: omp_bug2.c
* DESCRIPTION:
*   Another OpenMP program with a bug. 
* AUTHOR: Blaise Barney 
* LAST REVISED: 04/06/05 
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid;
float total;
unsigned long i;

omp_set_num_threads(2);
/*** Spawn parallel region ***/
#pragma omp parallel private(tid)
  {
  /* Obtain thread number */
  tid = omp_get_thread_num();
  /* Only master thread does this */
  if (tid == 0) {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  printf("Thread %d is starting...\n",tid);

  #pragma omp barrier

  /* do some work */
  total = 0.0;
  #pragma omp for schedule(dynamic,10) reduction(+:total)
  for (i=0; i<1000000; i++) 
     total = total + i*1.0;
  #pragma omp critical
  printf ("Thread %d is done! Total= %e\n",tid,total);

  } /*** End of parallel region ***/
}
