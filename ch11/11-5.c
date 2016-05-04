/*************************************************************************
	> 文件名: 11-5.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 15时35分11秒
 ************************************************************************/

#include<apue.h>
#include<pthread.h>

void cleanup(void* arg)
{
    printf("cleanup: %s\n", (char*)arg);
}

void* thr_fn1(void* arg)
{
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup, "thread 1 first handler");
    pthread_cleanup_push(cleanup, "thread 2 second handler");
    printf("thread 1 push complete\n");

    if(arg)
        pthread_exit((void*)1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    return (void*)0;
}

void* thr_fn2(void* arg)
{
    printf("pthread 2 start\n");

    pthread_cleanup_push(cleanup, "pthread 2 first handler");
    pthread_cleanup_push(cleanup, "pthread 2 second handler");

    if(!arg)
        pthread_exit((void*)2);

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return (void*)1;
}

int main()
{
    pthread_t tid1, tid2;
    int err;
    void* tret;

    pthread_create(&tid1, NULL, thr_fn1, (void*)1);
    pthread_create(&tid2, NULL, thr_fn2, (void*)1);

    pthread_join(tid1, &tret);
    printf("pthread 1 exit code: %ld\n", (long)tret);

    pthread_join(tid2, &tret);
    printf("pthread 2 exit code %ld\n", (long)tret);
}
