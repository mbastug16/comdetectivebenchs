#include <stdint.h>
#include <stdio.h>
#include "omp.h"
#include <stdlib.h>
#include <time.h>
#define N_ITER 100000000
#define NUM_THREADS 8

int globalSharedData;

int main(){
    int numThreads = NUM_THREADS;
    int tid;
    #pragma omp parallel private(tid) num_threads(numThreads)
    {
        tid = omp_get_thread_num();
        for(int i=0; i<N_ITER; i++){
        #pragma omp critical
            globalSharedData = globalSharedData + 3;
        }
    }
    return 0;
}

