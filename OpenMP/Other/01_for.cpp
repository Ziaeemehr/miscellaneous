#include<iostream>
#include<omp.h>
#define n 100


main(int argc, char *argv[]){
   int i;
   double a[n],b[n],c[n];
   double temp;
   
   for (i=0; i<n; i++)
       a[i] = c[i] = 1.;
   
#pragma omp paralel for private(temp) shared(a,b,c,n)
  {
    for (i=1;i<=n; i++){
        temp = 2. * a[i];
        a[i] = temp;
        b[i] = c[i]/temp;
    }
  }
}
