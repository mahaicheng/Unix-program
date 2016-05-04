/*************************************************************************
	> 文件名: 11-4.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 11时18分37秒
 ************************************************************************/

#include<apue.h>
#include<pthread.h>

struct foo
{
    int a, b, c, d;
};

void printfoo(const char* s, const struct foo* fp)
{
    printf("%s\n", s);
    printf("structure at 0x%lx\n", (unsigned long)fp);
    printf("foo.a = %d\n", fp->a);
    printf("foo.b = %d\n", fp->b);
    printf("foo.c = %d\n", fp->c);
    printf("foo.d = %d\n", fp->d);
}

void* thr_fn1(void* arg)
{
    struct foo freal = {1,2,3,4};

    printfoo("thread 1:", &freal);
    pthread_exit((void*)&freal);
}

void* thr_fn2(void* arg)
{
    printf("\nthread 2: ID is %lu\n", (unsigned long)pthread_self());
    pthread_exit((void*)0);
}

int main()
{
    pthread_t tid1, tid2;
    int err;
    struct foo* fp;

    pthread_create(&tid1, NULL, thr_fn1, NULL);
    pthread_join(tid1, (void*)&fp);

    printfoo("\nbefore thread 2 start:", fp);

    pthread_create(&tid2, NULL, thr_fn2, NULL);

    sleep(1);   //if not sleep, thread 2 may not has oppotunity to run before process exit

    printfoo("\nafter thread 2 exit:", fp);
}
