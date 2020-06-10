#include <stdint.h>
#include <stdio.h>
#include "omp.h"
#include <stdlib.h>
#include <time.h>
#define N_ITER 100000000

void foo(int** ptr){
    *ptr = malloc(sizeof(int));
}

int main(){
    int* sharedPtr = NULL;
    foo(&sharedPtr);
    int tid, private_sum;
    int numThreads = 8;
    #pragma omp parallel private(tid, private_sum) num_threads(numThreads)
    {
        tid = omp_get_thread_num();
        private_sum = 0;
        for(int i=0; i<N_ITER; i++){
           if(tid == 0 || tid == 1 && tid == i%2){
            *sharedPtr = 100;
           }
    #pragma omp barrier
           if(!(tid == 0 || tid == 1))
            private_sum = private_sum + *sharedPtr;
        }
    }
    return 0;
}

