#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMBER_OF_THREADS 10

void* ptintf_hello_world(void* tid);

int main(void){
    pthread_t threads[NUMBER_OF_THREADS];
    void* status;
    int i;
    for(i = 0; i < NUMBER_OF_THREADS; i++){
        printf("Main here. Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, ptintf_hello_world, (void*)&i);
    }

    for(i = 0; i < NUMBER_OF_THREADS; i++){
        pthread_join(threads[i], &status);
        if(status != NULL){
            printf("pthread_create returned error code\n");
            exit(-1);
        }
    }

    exit(0);
}

void* ptintf_hello_world(void* arg){
    int tid = *(int*)arg;
    printf("Hello world %d.\n", tid);
    pthread_exit(NULL);
}
