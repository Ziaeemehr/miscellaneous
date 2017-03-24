/*
 * Copyright (C) 2001-2013 The Abdus Salam, International Centre of Theoretical Physics (ICTP)
 *
 * This file is distributed under the terms of the GNU General Public License. 
 * See http://www.gnu.org/copyleft/gpl.txt 
 *
 * The code was developed for the hands-on session of the M1.2 - HPC Master SISSA/ICTP
 * 
 * Example of code for Matrix transpose with static allocation 
 *
 * Author: Ivan Girotto
 * Last update: Nov-2013
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>
#include <omp.h>
#include <math.h>


double second()
 /* Returns elepsed seconds past from the last call to timer rest */
{

    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}


int main( int argc, char * argv[] ) {

  double t1, t2, t11, t22;
  double *A, *AT,*AB;
  int i, j, k, l, blocksize;

#ifdef DEBUG
  FILE *fp;
#endif
double denom;
int pp;
denom = 0.;
int MATRIXDIM[7];

for (i=0;  i<7 ; i++){
   MATRIXDIM[i] = pow(2,i+7);
}
omp_set_num_threads(4);
blocksize = 4;

for(pp=0; pp<7; pp++){
  A  = (double* ) malloc( MATRIXDIM[pp] * MATRIXDIM[pp] * sizeof(double) ); 
  AT = (double* ) malloc( MATRIXDIM[pp] * MATRIXDIM[pp] * sizeof(double) ); 
  AB = (double* ) malloc( MATRIXDIM[pp] * MATRIXDIM[pp] * sizeof(double) ); 
  
  for( i = 0; i < MATRIXDIM[pp]; i++ ){
    for( j = 0; j < MATRIXDIM[pp]; j++ ){
      A[ (i * MATRIXDIM[pp]) + j] = (double) ( ( i * MATRIXDIM[pp] ) + j );
    }
  }

  //compute the number of block
  //nb = MATRIXDIM / BLOCKSIZE;
  // serial
  t1 = second();
  for (i = 0; i < MATRIXDIM[pp]; i += blocksize) {
    for (j = 0; j < MATRIXDIM[pp]; j += blocksize) {
        for ( k = i; k < i + blocksize; ++k) {
            for ( l = j; l < j + blocksize; ++l) {
                AT[k + l*MATRIXDIM[pp]] = A[l + k*MATRIXDIM[pp]];
            }
        }
    }
  }
  t2 = second();
  
  // parallel 
  t11 = second();
  /* Implement loops over the blocks of the main Matrices while transposing internally to the cache clock */
  #pragma omp parallel for private(i,j,k,l)
  for (i = 0; i < MATRIXDIM[pp]; i += blocksize) {
    for (j = 0; j < MATRIXDIM[pp]; j += blocksize) {
        for ( k = i; k < i + blocksize; ++k) {
            for ( l = j; l < j + blocksize; ++l) {
                AT[k + l*MATRIXDIM[pp]] = A[l + k*MATRIXDIM[pp]];
            }
        }
    }
  }
  
  t22 = second();

/*#ifdef DEBUG
  fp = fopen( "transpose.out", "w+b" );
  fwrite( AT, sizeof(double), MATRIXDIM[pp] * MATRIXDIM[pp], fp); 
  fclose( fp );
#endif 
*/
  //printf("%0.6g, %.6g \n", t2-t1, t22-t11);
  fprintf( stdout, " %d  %0.6g \n", MATRIXDIM[pp]/MATRIXDIM[0], (t2 - t1)/(t22-t11));
}
  free( A );
  free( AT );
  
  return 0;
}

  /*
  // To check the results
  for (i = 0; i < MATRIXDIM; i += blocksize) {
    for (j = 0; j < MATRIXDIM; j += blocksize) {
        for ( k = i; k < i + blocksize; ++k) {
            for ( l = j; l < j + blocksize; ++l) {
                AB[k + l*MATRIXDIM] = AT[l + k*MATRIXDIM];
            }
        }
    }
  }
  
  for( i = 0; i < MATRIXDIM; i++ ){
    for( j = 0; j < MATRIXDIM; j++ )
      printf("%.3g   ", A[i*MATRIXDIM+j]-AB[i*MATRIXDIM+j]);
    printf("\n");
  }
  */  
  
  /*
  //printing the matrix
  printf("Matrix A \n");
  for( i = 0; i < MATRIXDIM; i++ ){
    for( j = 0; j < MATRIXDIM; j++ )
      printf("%.3g   ", A[i*MATRIXDIM+j]);
    printf("\n");
  }

  printf("Matrix AT \n");
  for( i = 0; i < MATRIXDIM; i++ ){
    for( j = 0; j < MATRIXDIM; j++ )
      printf("%.3g   ", AT[i*MATRIXDIM+j]);
    printf("\n");
  }
  */

