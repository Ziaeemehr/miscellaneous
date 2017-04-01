#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
double seconds()
{
    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}

void PrintMatrix(double** M, int D);
double WallTime(void);
int i,j;

int main(int argc, char* argv[])
{
    using namespace std;
    // Read Input Parameters
    if(argc < 4) {
        cerr << "\nToo many input paramters.. should be four\n";
        exit(2);
    }

    int Dim = atoi(argv[1]);
    int Iterations = atoi(argv[2]);
    int RowPeek = atoi(argv[3]);
    int ColPeek = atoi(argv[4]);

    cout<<"\nInputs = " << Dim << " "<<Iterations << " " 
        << RowPeek << " " << ColPeek << "\n";

    if((RowPeek > Dim) || (ColPeek > Dim)){
        cerr << "Cannot Peek a matrix element outside of the surface";
        cerr << "Arguments 3 and 4 must be smaller than " << Dim;
        exit(3);
    }
    //allocate memory to matrix
    double **Matrix = new double*[Dim+2];
    double **Matrix_t = new double*[Dim+2];
    for (int i=0; i<Dim+2; i++) {
        Matrix[i] = new double[Dim+2];
        Matrix_t[i] = new double[Dim+2];
    }

    for (int i=0; i<Dim+2; i++)
        for (int j=0; j<Dim+2; j++)
            Matrix_t[i][j] = 0.0;
    
    //Fill initial values
    for( i=1;i<=Dim;i++)
        for( j=1;j<=Dim;j++)
            Matrix[i][j] = 0.5;
    
    // Set up Borders 
    double increment = 100.0/(Dim+1);

    for( i=1;i<=Dim+1;i++){
        Matrix[i][0] = Matrix[Dim+1][Dim+1-i] = i*increment;;
        Matrix_t[i][0] = Matrix_t[Dim+1][Dim+1-i] = i*increment;
        Matrix[i][Dim+1] = 0.0;
        Matrix_t[i][Dim+1] = 0.0;
        Matrix[0][i] = 0.0;
        Matrix_t[0][i] = 0.0;
    }
    //PrintMatrix(Matrix,Dim); 
    // Itertate
    double TimeStart = seconds();
    for(int iCount = 1; iCount <=Iterations; iCount++){
      
        //This will be a row dominant program.
        for( i=1;i<=Dim;i++)
            for( j=1;j<=Dim;j++)
                Matrix_t[i][j] = (0.25)*(Matrix[i-1][j] +
                                    Matrix[i][j+1] +
                                    Matrix[i+1][j] +
                                    Matrix[i][j-1]);
        //PrintMatrix(Matrix_t,Dim);
        double ** tmp;
        tmp = Matrix;
        Matrix = Matrix_t;
        Matrix_t = tmp;
    }
    double TimeEnd = seconds();
    cout<<"\n Time Iterations = "<<TimeEnd-TimeStart << " seconds";
    cout<< "\n Result Matrix["<<RowPeek<<"]["<<ColPeek<<"]="
        <<Matrix[RowPeek+1][ColPeek+1]<<"\n";

    for(int i = 0; i < Dim+2; ++i) {
        delete [] Matrix[i];
        delete [] Matrix_t[i];
    }
    delete [] Matrix;
    delete [] Matrix_t;

    return 0;
}

void PrintMatrix(double**Matrix, int Dim){
    using namespace std;
    cout << "\t";
    for( i=0;i<Dim+2;i++){
        cout << i << "\t";
    }
    cout << "\n";
    
  
    for( i=0;i<Dim+2;i++){
        cout << i << "\t";  
        for( j=0;j<Dim+2;j++){
            cout << Matrix[i][j] << "\t";
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
