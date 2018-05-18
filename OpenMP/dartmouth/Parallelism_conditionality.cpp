#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

// In this case, if parallelism_enabled evaluates 
// to a zero value, the number of threads in the 
// team that processes the for loop will always
// be exactly one.

int main(int argc, char *argv[])
{
    int parallelism_dnabled=1; //0 for one thread
    #pragma omp parallel for if(parallelism_dnabled)
    for (int c=0; c<10; c++)
        printf("hi from thread %d\n", omp_get_thread_num());

    return 0;
}