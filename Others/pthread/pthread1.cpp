#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* ptintf_hello_world(void* arg);

int main(void){
    pthread_t thread;
    int status, i = 10;
    printf("Main here. Creating thread %d\n", i);
    status = pthread_create(&thread, NULL, ptintf_hello_world, (void*)&i);// 创建线程
    
    if(status != 0){
        printf("pthread_create returned error code %d\n", status);
        exit(-1);
    }
    
    pthread_join(thread, NULL);// 等待线程完成

    exit(0);
}

void* ptintf_hello_world(void* arg){
    int tid = *(int*)arg;
    printf("Hello world %d.\n", tid);
    pthread_exit(NULL); // 使用pthread_exit退出线程
}
