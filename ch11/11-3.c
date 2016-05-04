/*************************************************************************
	> 文件名: 11-3.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 11时01分37秒
 ************************************************************************/

#include<apue.h>
#include<pthread.h>

void* thr_fn1(void* arg)
{
    printf("thread 1 returning\n");
    sleep(5);
    return (void*)99;
}

void* thr_fn2(void* arg)
{
    printf("thread 2 exiting\n");
    sleep(6);
    pthread_exit((void*)43);
}

int main()
{
    int err;
    pthread_t tid1, tid2;
    void* tret;

    pthread_create(&tid1, NULL, thr_fn1, NULL);
    pthread_create(&tid2, NULL, thr_fn2, NULL);

    pthread_join(tid1, &tret);
    printf("thread 1 exit code %ld\n", (long)tret);

    pthread_join(tid2, &tret);
    printf("thread 2 exit code %ld\n", (long)tret);
}
