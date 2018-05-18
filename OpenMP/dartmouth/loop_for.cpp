// Loop construct: for


#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    #pragma omp parallel
    {
    	#pragma omp for 
    	for (int i = 0; i < 10; ++i)
    	{
        	printf("%d ", i);
    	}
    }
    printf("\n");

    // equivalent to
	int this_thread = omp_get_thread_num(), num_threads = omp_get_num_threads();
	int my_start = (this_thread  ) * 10 / num_threads;
	int my_end   = (this_thread+1) * 10 / num_threads;
	for(int n=my_start; n<my_end; ++n)
		printf("%d ", n);

	printf("\n");

	#pragma omp parallel num_threads(3)
	{
		// This code will be executed by three threads.

		// Chunks of this loop will be divided amongst
		// the (three) threads of the current team.
		#pragma omp for
		for(int n=0; n<10; ++n) printf("%d ", n);
	}
	printf("\n");


    return 0;
}