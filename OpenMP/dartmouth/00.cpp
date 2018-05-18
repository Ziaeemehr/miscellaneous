#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    #pragma omp parallel
    {
        printf("Hello! \n");
    }

    return 0;
}