/*************************************************************************
	> 文件名: 10-10.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 19时48分25秒
 ************************************************************************/

#include<apue.h>

static void sig_alrm(int signo)
{
    printf("time expires!\n");
}

int main()
{
    char buf[MAXLINE];

    if(Signal(SIGALRM, sig_alrm) == SIG_ERR)
        err_sys("Signal error");

    alarm(10);

    int n;
    if((n = read(STDIN_FILENO, buf, MAXLINE)) < 0)
        err_sys("read error");

    alarm(0);

    if(write(STDOUT_FILENO, buf, n) != n)
        err_sys("write error");
}
