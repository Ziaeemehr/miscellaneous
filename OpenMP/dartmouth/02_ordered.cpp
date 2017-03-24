// Using OpenMP
// Portable Shared Memory Parallel Programming
// page 85

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>

static float a[1000], b[1000], c[1000];

void test(int first, int last){
    #pragma omp for schedule(static) ordered
    for (int i=first; i<=last; i++){
        if(i%2){
            #pragma omp ordered
            printf("test() iteration %d\n",i);
        }
    }
}

void test2(int iter){
    #pragma omp ordered
    printf("test2() iteration %d\n",iter);
}


int main(int argc, char *argv[]){
    int i;
    #pragma omp parallel
    {
        test(1,8);
        #pragma omp for ordered
        for (i=0; i<5; i++)
            test2(i);
    }
    return 0;
}
