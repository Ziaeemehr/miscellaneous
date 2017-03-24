#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define N  1000

int main(int argc, char *argv[]){
    int i;
    float a[N], b[N], c[N], d[N];
    // some initialization
    for (i=0; i<N; i++)
        a[i] = i * 1.0;
        b[i] = i * 1.5;

    #pragma omp parallel shared(a, b, c, d) \
    private(i)
    {
        #pragma omp sections nowait
        {
            #pragma omp section 
            for (i=0; i<N; i++)
                c[i] = a[i] + b[i];
            #pragma omp section
            for (i=0; i<N; i++)
                d[i] = a[i] * b[i];
        }
    }
    return 0;
}
