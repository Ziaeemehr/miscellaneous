#include<iostream>
#include<omp.h>
int main(int argc, char* argv[]){
   #pragma omp parallel 
   {
        int tid =omp_get_thread_num();
        if (tid==0)
            printf("Number of threads is: %d \n" , omp_get_num_threads());
        printf("Thread rank : %d \n ", omp_get_thread_num());
   }
}
