/*************************************************************************
	> 文件名: 10-26.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 08时29分16秒
 ************************************************************************/

#include<apue.h>

static void sig_int(int signo)
{
    printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
    printf("caught SIGCHLD\n");
}

int main()
{
    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal SIGINT error");
    if(signal(SIGCHLD, sig_chld) == SIG_ERR)
        err_sys("signal SIGCHLD error");

    if(system("/bin/ed") < 0)
        err_sys("system() error");
}
