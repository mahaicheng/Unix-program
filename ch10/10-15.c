/*************************************************************************
	> 文件名: 10-15.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 20时32分06秒
 ************************************************************************/

#include<apue.h>

static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    if(Signal(SIGQUIT, SIG_DFL) == SIG_ERR)
        err_sys("can't reset SIGQUIT");
}

int main()
{
    if(Signal(SIGQUIT, sig_quit) == SIG_ERR)
        err_sys("Signal error");

    sigset_t newmask, oldmask, pendmask;
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("sigprocmask error");

    sleep(5);

    if(sigpending(&pendmask) < 0)
        err_sys("sigpending error");
    if(sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("sigprocmask error");
    printf("SIGQUIT unblocked\n");

    pause();
}
