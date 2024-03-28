#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMBER_OF_THREADS 10

void* ptintf_hello_world(void* tid);
int main(void){
    pthread_t threads[NUMBER_OF_THREADS];
    int status,i;
    for(i=0;i<NUMBER_OF_THREADS;i++){//循环创建10个现场
    	printf("Main here. Creating thread %d",i);
        //创建线程，线程函数传入参数为i
    	status=pthread_create(&threads[i],NULL,ptintf_hello_world,(void*)&i);
        pthread_join(threads[i],NULL);
		if(status!=0){//线程创建不成功，打印错误信息
    		printf("pthread_create returned error code %d",status);
    		exit(-1);
		}
	}
	exit(0);
}
void* ptintf_hello_world(void* arg){
    int tid = *(int*)arg;
    printf("Hello world %d.\n", tid);
    pthread_exit(NULL); // 使用pthread_exit退出线程
}
