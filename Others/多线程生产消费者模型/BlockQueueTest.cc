#include "BlockQueue.hpp"
#include <ctime>
void *consumer(void *args)
{
    //创建阻塞队列
    BlockQueue<int> *bqp = static_cast<BlockQueue<int>* >(args);
    while (true)
    {
        sleep(2);
        int data = bqp->pop();
        cout << "consumer 消费数据完成: " << data << endl;
    }
}
void *productor(void *args)
{
    //创建阻塞队列
    BlockQueue<int> *bqp = static_cast<BlockQueue<int>* >(args);
    while (true)
    {
        //1、制作数据
        int data = rand() % 10;
        //2、生产数据
        bqp->push(data);
        cout << "productor 生产数据完成: " << data << endl;
        //生产慢一些
        // sleep(2);
    }
}
 
int main()
{
    // 定义一个阻塞队列
    // 创建两个线程, productor, consumer
    // 建立联系 productor ———— consumer
    srand((unsigned long)time(nullptr) ^ getpid());
    BlockQueue<int> bq;
    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, &bq);
    pthread_create(&p, nullptr, productor, &bq);
 
    pthread_join(c, nullptr);
    pthread_join(p, nullptr);
    return 0;
}