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

#define MATRIXDIM 4096

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

  double t1, t2;
  double *A, *AT;
  int i, j, k, l, blocksize;

#ifdef DEBUG
  FILE *fp;
#endif

  A = (double* ) malloc( MATRIXDIM * MATRIXDIM * sizeof(double) ); 
  AT = (double* ) malloc( MATRIXDIM * MATRIXDIM * sizeof(double) ); 
  

  for( i = 0; i < MATRIXDIM; i++ ){
    for( j = 0; j < MATRIXDIM; j++ ){
      A[ (i * MATRIXDIM) + j] = (double) ( ( i * MATRIXDIM ) + j );
    }
  }

  //compute the number of block
  //nb = MATRIXDIM / BLOCKSIZE;

  t1 = second();
  /* Implement loops over the blocks of the main Matrices while transposing internally to the cache clock */
 
  blocksize = 16;
  for (i = 0; i < MATRIXDIM; i += blocksize) {
    for (j = 0; j < MATRIXDIM; j += blocksize) {
        for ( k = i; k < i + blocksize; ++k) {
            for ( l = j; l < j + blocksize; ++l) {
                AT[k + l*MATRIXDIM] = A[l + k*MATRIXDIM];
            }
        }
    }
  }
  
  t2 = second();
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
#ifdef DEBUG
  fp = fopen( "transpose.out", "w+b" );
  fwrite( AT, sizeof(double), MATRIXDIM * MATRIXDIM, fp); 
  fclose( fp );
#endif  

  fprintf( stdout, "\n\nMatrix transpose time: %0.3g\n", t2 - t1 );

  free( A );
  free( AT );
  
  return 0;
}
