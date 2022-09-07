/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  文件编码格式为gb2312,cp936  
 *  $Id$ $DateTime$
 *  @file ProConer.c
 *  @brief 生产者与消费者模板
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author melvyn<chris.guyue@gmail.com>
 *  @date 2022-07-04    create
 *
 *  \details  1-创建五个生产者、每个生产者占用一个线程，生产者每2秒生产一个产品。五个生产者线程在某个时间里用很短的时间
 *              乱序的将产品放进仓库里。生产者进入仓库的顺序是不确定的，与 ID 无关。
 * 
 *            2-创建五个消费者，每个消费者占用一个线程，消费者每5秒消费一个产品。五个消费者线程在某个时间里用很短的时间
 *              乱序的将产品取出仓库里。消费者进入仓库的顺序是不确定的，与 ID 无关。
 * 
 *            3-生产者与消费者不会出现搬运产品相撞的情况，生产者左近左出，消费者右进右出，不是同一个门。之所以显示会出问题，
 *              是因为两个线程进行同时打印，在terminal打印出了bug。
 * 
 *            4-在达到一定时间后，因为生产者生产产品的速度大于消费者取出产品的速度，仓库一定会被挤满。
 *              当仓库被挤满时，已经生产完产品的生产者线程会被阻塞并被挂起，生产线程暂停，未生产完产品的生产者继续进行生产，
 *              生产完产品后，也进入阻塞等待的环节，直到消费者开始消费。
 *              当消费者从仓库取出产品时，被挂起的某一个生产者线程就会进入仓库，放进一个产品，之后回到线程继续生产，其他生
 *              产者继续按照队列进行等待。
 *                
 *********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sched.h>
#include <stdbool.h>
#include <string.h>

#define NumofProducer    5   
#define NumofConsumer    5   
#define SleepofProducer  2  
#define SleepofConsumer  5   
#define NumofStorage     50 

/* 生产者放置产品的位置 */
int InStockSite = 0;  
/* 消费者取产品的位置 */  
int OutofStockSite = 0; 
/* 缓冲初始化为0，开始时没有产品 */
int buff[NumofStorage] = { 0 }; 
/* 定义一个信号量，当仓库满时阻止生产者放产品，当没产品时阻止消费者消费 */
sem_t fullStock; 
sem_t emptyStock;  
/* 定义要用到互斥锁的线程，一次只有一个线程访问缓冲 */
pthread_mutex_t mutex_Producer;   
pthread_mutex_t mutex_Consumer;  
/* 生产者ID与消费者ID */
int ProducerID = 0; 
int ConsumerID = 0; 

//信号处理函数
void Handlesignal(int signo){
    printf("程序退出 %d\n",signo);
    exit(0);
}

/* 打印缓冲情况 */
void print() {
    int i;
    printf("产品队列为");
    char temp[NumofStorage+1];
    for(i = 0; i < NumofStorage; i++)
        if(buff[i]){
            temp[i]='*';
        }else{
            temp[i]='.';
        }
    temp[i]='\0';
    printf("%s\n",temp);
    fflush(stdout);
}

/**
 * @fn     product
 * @brief  生产者方法
 * @param  无 
 * @return 
 */
void *product() {
    int id = ++ProducerID;
    while(1) {
        sleep(SleepofProducer); /* 生产者每2秒生产一个产品 */
        sem_wait(&fullStock);   /* 当仓库满了时，阻止生产者放产品,线程处于阻塞状态 */
        pthread_mutex_lock(&mutex_Producer); /* 互斥锁，一次只有一个线程访问缓冲 */

        InStockSite= InStockSite % NumofStorage;
        printf(" + 生产者%d在产品队列中放入第%d个产品\t",id, InStockSite);
        fflush(stdout); /* 在printf()后使用fflush(stdout)的作用是立刻将要输出的内容输出 */

        buff[InStockSite]= 1;/* 仓库中的位置有产品时，仓库的地址位1 */
        print();
        ++InStockSite;

        pthread_mutex_unlock(&mutex_Producer);
        sem_post(&emptyStock); /* 当仓库空了时执行此函数，让生产者继续工作 */
    }
}

/**
 * @fn     prochase
 * @brief  消费者方法
 * @param  无 
 * @return 
 */
void *prochase() {
    int id = ++ConsumerID;
    while(1) {
        sleep(SleepofConsumer);/* 消费者每2秒生产一个产品 */
        sem_wait(&emptyStock); /* 当空了时执行此函数，阻止消费者取产品 阻塞等待 */
        pthread_mutex_lock(&mutex_Consumer);

        OutofStockSite= OutofStockSite % NumofStorage;
        printf(" - 消费者%d从产品队列中取出第%d个产品\t",id, OutofStockSite);
        fflush(stdout);

        buff[OutofStockSite]= 0;/* 仓库中的位置没有产品时，仓库的地址位0 */
        print();
        ++OutofStockSite;

        pthread_mutex_unlock(&mutex_Consumer);
        sem_post(&fullStock);/* 当仓库满了时执行此函数，让消费者继续工作 */
    }
}


int main() {
    printf("生产者%d个和消费者%d个,"
            "产品缓冲为%d,生产者每%d秒生产一个产品,"
            "消费者每%d秒消费一个产品,Ctrl+退出程序\n",
             NumofProducer,NumofConsumer,NumofStorage,SleepofProducer,SleepofConsumer);
    pthread_t id1[NumofConsumer];
    pthread_t id2[NumofProducer];
    int i;
    int ret[NumofConsumer+NumofProducer];
    //结束程序
    if(signal(SIGINT,Handlesignal)==SIG_ERR){/* 按ctrl+C产生SIGINT信号 */
        printf("信号安装出错\n");
    }

//TODO: 初始化同步信号量
    /* ret = sem_init(&sem, pshared, value); 
     * 如果 pshared 的值为零，则不能在进程之间共享信号。如果 pshared 的值不为零，则可以在进程之间共享信号。
     **/
    int ini1 = sem_init(&fullStock, 0, NumofStorage);//产品队列缓冲同步
    int ini2 = sem_init(&emptyStock, 0, 0);//线程运行同步
    if(ini1 && ini2 != 0) {
        printf("信号量初始化失败！\n");
        exit(1);
    }

//TODO: 初始化互斥信号量
    int ini3 = pthread_mutex_init(&mutex_Producer, NULL);
    int ini4 = pthread_mutex_init(&mutex_Consumer, NULL);
    if(ini3 != 0 ||ini4!=0) {
        printf("线程同步初始化失败！\n");
        exit(1);
    }

//TODO: 创建N个生产者线程
    for(i = 0; i < NumofProducer; i++) {
        /* 函数：pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg);
         * 第一个参数，用来保存创建好后线程 uid
         * 第二个参数，即线程属性，通常传 NULL，表示默认属性，这个属性在创建前可以设置，包括调度策略，栈大小，优先级等等
         * 第三个参数，即线程入口函数
         * 第四个参数，传给线程的参数
         */
        ret[i]= pthread_create(&id1[i], NULL, product, (void *) (&i));
        if(ret[i] != 0) {
            printf("生产者%d线程创建失败\n", i);
            exit(1);
        }

    }

//TODO: 创建N个消费者线程
    for(i = 0; i < NumofConsumer; i++) {
        ret[i]= pthread_create(&id2[i], NULL, prochase, NULL);
        if(ret[i] != 0) {
            printf("消费者%d线程创建失败\n", i);
            exit(1);
        }
    }

//TODO: 等待线程销毁
    for(i = 0; i < NumofProducer; i++) {
        pthread_join(id1[i], NULL);
        pthread_join(id2[i],NULL);
    }

    exit(0);
}