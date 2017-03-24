#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#define N  20

int main(int argc, char *argv[]){
    int i;
    float a[N];
    float sum = 0.0;
    // some initializations
    for (i=0; i<N; i++)
        a[i] = i;

    // #pragma omp parallel for reduction(+:sum) num_threads(2)
    // for (i=0; i<N; i++){
    //     sum = sum + a[i];
    // }

    #pragma omp parallel for default(none) \
    shared(a) private(i) reduction(+:sum)  num_threads(2)
    for (i=0; i<N; i++){
        sum = sum + a[i];
    }

    printf("sum is %f\n",sum);
    return 0;
}
