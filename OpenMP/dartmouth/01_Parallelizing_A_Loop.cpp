#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#define N  20

int main(int argc, char *argv[]){
    int nthreads, tid,i;
    float a[N], b[N], c[N];
    // some initializations
    for (i=0; i<N; i++)
        a[i] = b[i] = i;
    // omp_set_num_threads(2);
    #pragma omp parallel shared(a,b,c,nthreads) \
    private(i,tid) num_threads(2)
    {
        tid = omp_get_thread_num();
        printf("Thread %d starting ...\n",tid);
        #pragma omp for
        for (i=0; i<N; i++){
            c[i] = a[i]+b[i];
            printf("Thread %d: c[%d] = %f \n",tid,i,c[i]);
        }
    }

    int j = 5;
    #pragma omp parallel for firstprivate(j)
    for (i=1; i<=N; i++) {
        if(i == 1 || i == N)
            j = j+1;
        a[i] = a[i] + j; 
    }
    
    return 0;
}
