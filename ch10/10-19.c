/*************************************************************************
	> 文件名: 10-19.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月16日 星期三 10时45分52秒
 ************************************************************************/

#include<apue.h>

Sigfunc* signal_intr(int signo, Sigfunc* func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

#ifdef SA_INTERRUPT
    act.sa_flags |= SA_INTERRUPT;
#endif
    if(sigaction(aigno, &act, &oact) < 0)
        return (SIG_ERR);
    return (oact.sa_handler);
}
