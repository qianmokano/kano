#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <cstdint>
#define NUMBER_OF_THREADS 10

void* ptintf_hello_world(void* tid);

int main(void){
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    for(i = 0; i < NUMBER_OF_THREADS; i++){
        printf("Main here. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, ptintf_hello_world, (void*)(intptr_t)i);
        if(status != 0){
            printf("pthread_create returned error code %d\n", status);
            exit(-1);
        }
    }

    for(i = 0; i < NUMBER_OF_THREADS; i++){
        int* res;
        pthread_join(threads[i], (void**)&res);
        printf("res[%d]: %d\n", i, *res);
        free(res); // 释放线程函数中分配的内存空间
    }

    exit(0);
}

void* ptintf_hello_world(void* arg){
    int tid = (intptr_t)arg;
    printf("Hello world %d.\n", tid);
    int* result = (int*)malloc(sizeof(int));
    *result = tid * tid;
    return result;
}
