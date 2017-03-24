#include <iostream>
#include <omp.h>


int main (int argc, const char * argv[])
{

    int nProcessors=omp_get_max_threads();

    std::cout<<nProcessors<<std::endl;


    omp_set_num_threads(nProcessors);
    std::cout<<"number of threads outside: " <<omp_get_num_threads()<<std::endl;


#pragma omp parallel for 
    for(int i=0;i<5;i++){
        int tid=omp_get_thread_num();
        std::cout<<tid<<"\t tid"<<std::endl;
        int nThreads=omp_get_num_threads();
        std::cout<<nThreads<<"\t nThreads"<<std::endl;
    }
    return 0;
}
