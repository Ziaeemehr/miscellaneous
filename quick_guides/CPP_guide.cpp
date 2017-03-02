// timing
#include <time.h>
clock_t t;
t = clock();
//do something
t = clock() - t;
  printf ("It took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
  
  
// initialize array
int foo [5] = { 16, 2, 77, 40, 12071 }; 
int foo[] = { 10, 20, 30 };
int foo[] { 10, 20, 30 }; 
// initialize vector

vector< vector<int> > fog { { 1, 1, 1 },
                            { 2, 2, 2 } };

#include<iostream>
using namespace std;
int main(){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9,10};
    int size1=5;
    int size2=5;
    int * result = new int[size1 + size2];
    copy(arr1, arr1 + size1, result);
    copy(arr2, arr2 + size2, result + size1);    
}

##vector 
vector<int> v(2)={34,23};


## multidimensional vector:
// Declaration of a matrix with 3 rows and 4 columns
vector< vector<int> > my_matrix(3,vector<int>(4));

typedef vector<int> Dim1;
typedef vector<Dim1> Dim2;
typedef vector<Dim2> Dim3;
typedef vector<Dim3> Matrix4D;
Matrix4D my_matrix(5,Dim3(i+1,Dim2(n,Dim1(9))));


// A more elegant declaration
typedef vector<int> Row;        // One row of the matrix
typedef vector<Row> Matrix;     // Matrix: a vector of rows
Matrix my_matrix(3,Row(4));
#initialize  2D arrays:

int const A::test[10][10];           // uninitialized
int const A::test[10][10] = { {0} }; // all elements initialized to 0.
int const A::test[10][10] = {1,2};   // test[0][0] ==1, test[0][1]==2, rest==0
int const A::test[10][10] = { 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 7, 7, 7, 7, 0, 0, 0}, 
  {0, 0, 0, 7, 7, 7, 7, 0, 0, 0}, 
  {0, 0, 0, 7, 7, 7, 7, 0, 0, 0}, 
  {0, 0, 0, 7, 7, 7, 7, 0, 0, 0}
};




// Set one array equal to another without a loop
int a[5] = {1,2,3,4,5};
int b[5] = {5,4,3,2,1};

memcpy(a, b, sizeof(a));
// or 
void copy(int *a, int *b, int b_size) {
     if(b_size == 0) return;    
     *a = *b;
     copy(++a, ++b, b_size-1);
}

std::copy(std::begin(b), std::end(b), std::begin(a));
// or
std::array<int, 5> a = {1,2,3,4,5};
std::array<int, 5> b = {5,4,3,2,1};
a = b;
// or
// also work with vector


//save to file with variable filename
string f1="./../data/pot"+to_string(ensemble)+".txt";
char const *file1 = f1.c_str();
FILE *ofile;
ofile = fopen(file1,"w");
for (int i=0; i<nsteps; i++)
    fprintf(ofile,"%15.9f ",i*dt);
fprintf(ofile,"\n");    
for (int i=0; i<Node; i++){
    for (int j=0; j<nsteps; j++)
        fprintf(ofile,"%15.9f ",X[i][j]);
    fprintf(ofile,"\n");
}
fclose(ofile);

double **Matrix;
Matrix = (double**)malloc(sizeof(double*)*(Dim));  
for(i=0;i<Dim;i++)
    Matrix[i] = (double*)malloc(sizeof(double)*(Dim));

for( i=0;i<Dim;i++){
    for( j=0;j< Dim;j++)
       Matrix[i][j] = 0.0;
}

// allocation by new
//1D
foo = new int [5];  // if allocation fails, an exception is thrown
foo = new (nothrow) int [5]; 
// e.g:
int * foo;
foo = new (nothrow) int [5];
if (foo == nullptr) {
  // error assigning memory. Take measures.
}
int * p;
p= new (nothrow) int[i];
delete[] p;

//2D
int** ary = new int*[rowCount];
for(int i = 0; i < rowCount; ++i)
    ary[i] = new int[colCount];
//or
int **ary = new int*[sizeY];
for(int i = 0; i < sizeY; ++i) {
    ary[i] = new int[sizeX];
}
// and then clean up would be:
for(int i = 0; i < sizeY; ++i) {
    delete [] ary[i];
}
delete [] ary;

// An alternative approach would be to use one large block of memory:
int *ary = new int[sizeX*sizeY];
// ary[i][j] is then rewritten as
ary[i*sizeY+j]
