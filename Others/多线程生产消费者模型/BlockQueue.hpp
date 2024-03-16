#pragma once
#include <iostream>
#include <queue>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
using namespace std;
 
// 定义默认容量大小为5
const uint32_t gDefaultCap = 5;
 
template <class T>
class BlockQueue
{
public:
    // 构造函数
    BlockQueue(uint32_t cap = gDefaultCap)
        : cap_(cap)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&conCond_, nullptr);
        pthread_cond_init(&proCond_, nullptr);
    }
    // 析构函数
    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&conCond_);
        pthread_cond_destroy(&proCond_);
    }

public:
    // 生产函数
    void push(const T &in) // const &: 纯输入
    {
        // 加锁
        // 判断 -> 是否适合生产 -> bq_是否满 -> 程序员视角的条件 -> 1、满(不生产) 2、不满(生产)
        // if(满) 不生产，休眠
        // else if(不满) 生产
        // 解锁
        lockQueue();
        while (isFull())
        {
            //before: 当我等待的时候，会自动释放mutex_
            proBlockWait(); // 阻塞等待，等待被唤醒
            //after: 当我醒来的时候，我是在临界区里醒来的
        }
        // 条件满足，可以生产
        pushCore(in); // 生产完成
        // 解锁
        unlockQueue();
        // 生产数据后唤醒消费者消费数据
        wakeupCon();
    }
    // 消费接口
    T pop()
    {
        // 加锁
        // 判断 -> 是否适合消费 -> bq_是否为空 -> 程序员视角的条件 -> 1、空(不消费) 2、有(消费)
        // if(空) 不消费，休眠
        // else if(有) 消费
        // 解锁
        lockQueue();
        if (isEmpty())
        {
            conBlockWait(); // 阻塞等待，等待被唤醒
        }
        // 条件满足，可以消费
        T tmp = popCore();
        // 解锁
        unlockQueue();
        // 消费数据后唤醒生产者生产数据
        wakeupPro();
        return tmp;
    }
 
private:
    // 加锁
    void lockQueue()
    {
        pthread_mutex_lock(&mutex_);
    }
    // 解锁
    void unlockQueue()
    {
        pthread_mutex_unlock(&mutex_);
    }
    // 判空
    bool isEmpty()
    {
        return bq_.empty();
    }
    // 判满
    bool isFull()
    {
        return bq_.size() == cap_;
    }
    // 生产者等待
    void proBlockWait() // 生产者一定是在临界区的
    {
        // 1、在阻塞线程的时候，会自动释放mutex_锁，维持生产者和消费者的互斥关系
        pthread_cond_wait(&proCond_, &mutex_);
        // 2、当阻塞结束，返回的时候，pthread_cond_wait，会自动帮我们重新获得mutex_锁，然后才返回
    }
    // 消费者等待
    void conBlockWait() // 阻塞等待，等待被唤醒
    {
        // 1、在阻塞线程的时候，会自动释放mutex_锁，维持生产者和消费者的互斥关系
        pthread_cond_wait(&conCond_, &mutex_);
        // 2、当阻塞结束，返回的时候，pthread_cond_wait，会自动帮我们重新获得mutex_锁，然后才返回
    }
    // 唤醒生产者
    void wakeupPro()
    {
        pthread_cond_signal(&proCond_);
    }
    // 唤醒消费者
    void wakeupCon()
    {
        pthread_cond_signal(&conCond_);
    }
    // 生产数据
    void pushCore(const T &in)
    {
        bq_.push(in);
    }
    // 消费数据
    T popCore()
    {
        T tmp = bq_.front();
        bq_.pop();
        return tmp;
    }
 
private:
    uint32_t cap_;           // 容量
    queue<T> bq_;            // blockqueue阻塞队列
    pthread_mutex_t mutex_;  // 保护阻塞队列的互斥锁
    pthread_cond_t conCond_; // 让消费者等待的条件变量
    pthread_cond_t proCond_; // 让生产者等待的条件变量
};