// The other threads wait at a barrier until the 
// thread executing the single code block has completed.

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void work1() {}
void work2() {}
void single_example(){
    #pragma omp parallel num_threads(2)
    {
        #pragma omp single nowait
        {
            printf("Beginning work1. \n");
            work1();
        }
        #pragma omp single 
        printf("Finishing work1. \n");

        #pragma omp single nowait
        {
            printf("Beginning work2. \n");
            work2();
        }
        #pragma omp single 
        printf("Finishing work2. \n");
    }
}

int main(int argc, char *argv[]){

    single_example();

    return 0;
}
