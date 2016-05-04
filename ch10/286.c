/*************************************************************************
	> 文件名: 286.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 21时52分52秒
 ************************************************************************/

#include<apue.h>

static void sig_int(int signo)
{
    pr_mask("\nin sig_int: ");
}

int main()
{
    pr_mask("before blocked: ");

    sigset_t newmask, oldmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("sigprocmask SIGINT error");

    pr_mask("after blocked: ");

    sleep(5);

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("sigprocmask error");

    pr_mask("after unblocked: ");
    sleep(1);
    pause();
}
