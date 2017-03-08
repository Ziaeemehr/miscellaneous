#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<time.h>
#include <sys/time.h>
#include<vector>
#include<array>

using namespace std;
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
int main(){
    

const int n = 2000; 
int num_sim = 1;
double  wall0,wall1;
wall0 = get_wall_time();
auto A0 = new int [n*n];
for (int num=0; num<num_sim; num++){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A0[i*n+j] = i+j;
//             cout << A0[i+n+j]<<" ";
        }}}

	  
wall1 = get_wall_time();
cout << "Wall Time = " << wall1 - wall0 << endl;

return 0;
}