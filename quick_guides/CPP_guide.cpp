// timing
#include <time.h>
clock_t t;
t = clock();
//do something
t = clock() - t;
  printf ("It took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
  


// wall time and cpu time 
#include <time.h>
#include <sys/time.h>
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
double get_cpu_time(){
    return (double)clock() / CLOCKS_PER_SEC;
}

  
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

# valarray  section 40.5.1 
valarray va {};         //valarray with no elements
valarray va {n};        //valarray of n elements with value T{}; explicit
valarray va {t,n};      //valarray of n elements with value t
valarray va {p,n};      //valarray o f n elements with values copied from [p:p+n) 
valarray va {v2};       //Move and copy constructor
valarray va {a};        //construct va with elements from a;

valarray<double> v0;         //placeholder
valarray<double> v1(1000);   // 1000 elements with value float()==0.0F
valarray<int> v2(-1,2000);   // 2000 elements with value -1
valarray<double> v4=v3       // v4 has v2.size() elements
valarray<int> v5{-1,2000};   // two elements




std::valarray<int> foo (10);
for (int i=0; i<10; ++i) foo[i]=i;

double val[] = {1.5, 3.1, 5.5};
std::valarray<double> foo (val,3);
std::valarray<double> bar = cos (foo);
for (std::size_t i=0; i<foo.size(); ++i)
      std::cout << ' ' << foo[i];
for (std::size_t i=0; i<bar.size(); ++i)
      std::cout << ' ' << bar[i];
// foo: 1.5 3.1 5.5
// bar: 0.0707372 -0.999135 0.70867
double val[] = {1.0, 2.0, 4.0, 8.0};
std::valarray<double> foo (val,4);
std::valarray<double> bar = exp (foo);

int init[]={0,10,20,30};
std::valarray<int> myvalarray (init,4);
std::cout << "The sum is " << myvalarray.sum() << '\n';
// The sum is 60


# 2d valarray
typedef valarray<valarray<int> > va2d;
va2d mat(valarray<int>(4), 10);  // (col,row)
cout << "row " << M.size() <<endl; 
cout << "col " << M[0].size() << endl; 


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

// short and simple save to file
ofstream myfile;
myfile.open ("example.txt");
myfile << "Writing this to a file.\n";
myfile.close();


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

// pusg_back to a 2D vector
std::vector<std::vector <int> > normal;
for(int i=0;i<5;i++)
{
    normal.push_back(std::vector<int>());
    for(int j=0;j<10;j++)
    {    
        normal[i].push_back(j);    
    }
}
// initialze a pointer array to zero:
/* http://stackoverflow.com/a/2615245/784433 */
struct S {
  int *a[100];

  S() : a() {
    // `a` contains null pointers 
  }
};
int *a = new int[100]();
// `a[i]` contain null pointers
int *a[100] = {};
// `a` contains null pointers 


