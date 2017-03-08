#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<time.h>
#include <sys/time.h>
#include<vector>
#include<array>

using namespace std;
const int n = 5000;
int num_sim = 200;

double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

//---------------------------------------------------//
//---------------------------------------------------//
int main()
{
    
    double wall0;
    double wall1;
    //NEW---------------------------------------------//
    wall0 = get_wall_time();
    
    int **A0;
    A0 = new int*[n];
    for (int i=0; i<n; i++)
        A0[i] = new int[n];
//     auto A0 = new int [n][n]();
    for (int num=0; num<num_sim; num++)
       for (int i=0; i<n; i++) 
	  for (int j=0; j<n; j++) 
              A0[i][j] = i+j;
	  
    wall1 = get_wall_time();
    cout << "new [i][j] Time = " << wall1 - wall0 << endl;
    
    for (int i=0; i<n; i++)
        delete [] A0[i];
//     delete [] A0;
    
    ////////////////////////////////////////////////////
    wall0 = get_wall_time();
    auto A1 = new int [n*n];
    for (int num=0; num<num_sim; num++)
       for (int i=0; i<n; i++) 
	  for (int j=0; j<n; j++) 
              A1[i*n+j] = i+j;
        
    wall1 = get_wall_time();
    cout << "new [i*n+j] = " << wall1 - wall0 << endl;
    delete [] A1;
    
    //VECTOR------------------------------------------//
    
    wall0 = get_wall_time();
    typedef vector<vector<int> > Matrix;
    Matrix A2(n,vector<int> (n));

    for (int num=0; num<num_sim; num++)
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) 
                A2[i][j] = i+j;
            
    wall1 = get_wall_time();
    cout << "vector [i][j] = " << wall1 - wall0 << endl;
    
    
    wall0 = get_wall_time();
    vector<int> A3(n*n);
    for (int num=0; num<num_sim; num++)
       for (int i=0; i<n; i++) 
	  for (int j=0; j<n; j++) 
              A3[i*n+j] = i+j;
          
    wall1 = get_wall_time();
    cout << "vector [i*n+j] = " << wall1 - wall0 << endl;
    
    
    //STD:ARRAY---------------------------------------//
    
//     wall0 = get_wall_time();
//     array<array<int,n>, n>  A2;
//     for (int num=0; num<num_sim; num++){
//         for(int i=0; i<n; i++){
//             for (int j=0; j<n; j++){
//                 A[i][j] = i+j;
//             }
//         }
//     }
//     wall1 = get_wall_time();
//     cout << "Wall Time = " << wall1 - wall0 << endl;
    
    return 0;    
}    

//----------------------------------------------------//



// void display_timing(clock_t timeit) 
// {      
//     double time;
//     int hour;
//     int minute;
//     double second;
//     time = ((double)timeit)/CLOCKS_PER_SEC;
//     hour = (int) time/3600;
//     minute = ((int)time % 3600)/60;
//     second = time-(3600.*hour+60.*minute);
//     printf ("It took %d minutes and %.4f seconds.\n",minute,second);
// }
