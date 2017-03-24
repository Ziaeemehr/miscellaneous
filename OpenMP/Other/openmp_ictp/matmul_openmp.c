/*
 * This code is created for teaching purpose at the ICTP SMR2877 activity 
 * "Introductory School on Parallel Programming and Parallel Architecture for High-Performance Computing"
 *
 * Author: Ivan Girotto (igirotto@ictp.it)
 * Last Revision: October 2016
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>
#include <cblas.h>
#include <omp.h>
/* Define the Matrix size */
#define SIZE 1024 


/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}


int main(int argc, char * argv[]){

  /* Variables Declaration */
  double *A, *B, *C, *C_BLAS, temp;
  //double *C,*C_BLAS,temp;
  int i = 0, j = 0, k = 0;
  double t_start, t_end;
  /* Dynamic Memory Allocation */
    A = (double *)malloc(SIZE * SIZE * sizeof(double));
    B = (double *)malloc(SIZE * SIZE * sizeof(double));
    C = (double *)malloc(SIZE * SIZE * sizeof(double));
    C_BLAS = (double *)malloc(SIZE * SIZE * sizeof(double));

  /* Initialization to 0.0 for the output matrixes */
  memset( C, 0, SIZE * SIZE * sizeof(double) );
  memset( C_BLAS, 0, SIZE * SIZE * sizeof(double) );
  //memset( A, 0, SIZE * SIZE * sizeof(double) );
  //memset( B, 0, SIZE * SIZE * sizeof(double) );
  
  /* Initialization (random values) for the input matrixes */ 
  for( i = 0; i < SIZE; i++ ){
     for( j = 0; j < SIZE; j++ ){
         A[i * SIZE + j] = i+j; //rand() % 100;
         B[i * SIZE + j] = i-j; //rand() % 100;
     }
  }

  /* Start the timer */

  t_start = seconds();

  omp_set_num_threads(8);  
  #pragma omp parallel for private(i,j,k) 
  /* Naive implementation of a matrix multiplication */
  for (i=0; i<SIZE; i++){
      for(j=0; j<SIZE; j++){
          for (k=0; k<SIZE; k++){
              C[i * SIZE +j ] += A[i*SIZE+k]*B[k*SIZE+j];
          }
      }
  }
  
  /* Stop the timer */
  t_end = seconds();
  /*for (i=0; i<SIZE; i++)
  {
      for(j=0; j<SIZE; j++)
         printf("%.3g     ", C[i*SIZE+j]);
      printf("\n");
  }
  */
  /* Print on standard output the obtained time to solution using "naive" implementation */ 
  fprintf( stdout, "\n\tMatrix Multiplication completed. Time to solution of \"naive\" version = %.3g seconds\n\n", t_end - t_start );


  /* execution of a Matrix Multiplication C = A x B, using Linux internal BLAS library */
  t_start = seconds();

  /* Execution of DGEMM operation using standard BLAS interface */
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, SIZE, SIZE, SIZE, 1.0, A, SIZE, B, SIZE, 0.0, C_BLAS, SIZE);

  t_end = seconds();

  /* Print on standard output the obtained time to solution using "DGEMM" standard BLAS interface */  
  fprintf( stdout, "\n\tMatrix Multiplication completed. Time to solution of Linux internal BLAS version = %.3g seconds\n\n", t_end - t_start );

 /* for (i=0; i<SIZE; i++)
  {
      for(j=0; j<SIZE; j++)
         printf("%.3g     ", C_BLAS[i*SIZE+j]);
      printf("\n");
  }
  */
 
  /* Memory deallocation */
free(A);
free(B);
free(C);
free(C_BLAS);
  return 0;
}
