#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <omp.h>


/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}


void PrintSurfaceMatrix(double** M, int D);
double WallTime(void);
int i,j;

int main(int argc, char* argv[]){
  using namespace std;
  // Read Input Parameters
  if(argc < 4) {
    cerr << "\nToo many input paramters.. should be four\n";
    exit(2);
  }

  int Dimension = atoi(argv[1]);
  int Iterations = atoi(argv[2]);
  int RowPeek = atoi(argv[3]);
  int ColPeek = atoi(argv[4]);
  //cout <<"\nInputs = " << Dimension << " "<<Iterations << " " 
  //     << RowPeek << " " << ColPeek << "\n";

  if((RowPeek > Dimension) || (ColPeek > Dimension)){
    cerr << "Cannot Peek a matrix element outside of the surface";
    cerr << "Arguments 3 and 4 must be smaller than " << Dimension;
    exit(3);
  }
  
  // Initialize Matrix
  //omp_set_num_threads(4);
  double **SurfaceMatrix;
  SurfaceMatrix = (double**)malloc(sizeof(double*)*(Dimension+2));

  double **SurfaceMatrix_t;
  SurfaceMatrix_t = (double**)malloc(sizeof(double*)*(Dimension+2));


  #pragma omp parallel 
  {
#pragma omp for private(i) 
    for(i=0;i<Dimension+2;i++)
      SurfaceMatrix[i] = (double*)malloc(sizeof(double)*(Dimension+2));
    
#pragma omp for private(i,j) 
    for( i=0;i<Dimension+2;i++){
      SurfaceMatrix_t[i] = (double*)malloc(sizeof(double)*(Dimension+2));
      for( j=0;j< Dimension+2;j++)
	SurfaceMatrix_t[i][j] = 0.0;
  }
    
    //Fill initial values
#pragma omp for private(i,j) 
    for( i=1;i<=Dimension;i++)
      for( j=1;j<=Dimension;j++)
      SurfaceMatrix[i][j] = 0.5;
    
    // Set up Borders 
    double increment = 100.0/(Dimension+1);
#pragma omp for private(i) 
    for( i=1;i<=Dimension+1;i++){
    SurfaceMatrix[i][0]=SurfaceMatrix[Dimension+1][Dimension+1-i]=i*increment;;
    SurfaceMatrix_t[i][0]=SurfaceMatrix_t[Dimension+1][Dimension+1-i]=i*increment;
    SurfaceMatrix[i][Dimension+1]=0.0;
    SurfaceMatrix_t[i][Dimension+1]=0.0;
    SurfaceMatrix[0][i] = 0.0;
    SurfaceMatrix_t[0][i] = 0.0;
    }
    //PrintSurfaceMatrix(SurfaceMatrix,Dimension); 
    // Itertate
    double TimeStart = seconds();
    for(int iCount = 1; iCount <=Iterations; iCount++){
      
      //This will be a row dominant program.
      int myid = omp_get_thread_num();
      int nths = omp_get_num_threads();
      int my_start = myid * (Dimension/nths) + 1;
      int my_end = my_start + (Dimension/nths) - 1; 
      #pragma omp for private(i,j) 
      for( i=my_start;i<=my_end;i++)
	for( j=1;j<=Dimension;j++)
	  SurfaceMatrix_t[i][j] = (0.25)*(SurfaceMatrix[i-1][j] +
					  SurfaceMatrix[i][j+1] +
					  SurfaceMatrix[i+1][j] +
					  SurfaceMatrix[i][j-1]);
      //PrintSurfaceMatrix(SurfaceMatrix_t,Dimension);
#pragma omp master
      {    
	double ** tmp;
	tmp = SurfaceMatrix;
	SurfaceMatrix = SurfaceMatrix_t;
	SurfaceMatrix_t = tmp;
      }
#pragma omp barrier
    }
    double TimeEnd = seconds();
  //cout <<"\n Time Iterations = "<<TimeEnd-TimeStart << " seconds";
//    cout << "\n Result SurfaceMatrix["<<RowPeek<<"]["<<ColPeek<<"]="
//         <<SurfaceMatrix[RowPeek+1][ColPeek+1]<<"\n";
#pragma omp master
  {
  cout << Dimension << "\t" << TimeEnd-TimeStart;
  cout << "\n";
  }
  #pragma omp for private(i) 
  for( i=0;i<Dimension+2;i++){
    free(SurfaceMatrix[i]);
    free(SurfaceMatrix_t[i]);
  }
}
  free(SurfaceMatrix);
  free(SurfaceMatrix_t);
  return 0;
}

void PrintSurfaceMatrix(double**SurfaceMatrix, int Dimension){
  using namespace std;
  cout << "\t";
  for( i=0;i<Dimension+2;i++){
    cout << i << "\t";
  }
  cout << "\n";
  
  
  for( i=0;i<Dimension+2;i++){
    cout << i << "\t";  
    for( j=0;j<Dimension+2;j++){
      cout << SurfaceMatrix[i][j] << "\t";
    }
    cout << "\n";
  }
}

// A Simple timer for measuring the walltime
double WallTime(void){
  static long zsec =0;
  static long zusec = 0;
  double esec;
  struct timeval tp;
  struct timezone tzp;
  gettimeofday(&tp, &tzp);
  if(zsec ==0) zsec  = tp.tv_sec;
  if(zusec==0) zusec = tp.tv_usec;
  esec = (tp.tv_sec-zsec)+(tp.tv_usec-zusec)*0.000001;
  return esec;
}
