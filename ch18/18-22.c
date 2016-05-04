/*************************************************************************
	> 文件名: 18-22.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月12日 星期四 11时40分48秒
 ************************************************************************/

#include<apue.h>
#include<termios.h>
#include<sys/ioctl.h>

static void pr_winsize(int fd)
{
    struct winsize size;

    if(ioctl(fd, TIOCGWINSZ, (char*)&size) < 0)
        err_sys("ioctl error");

    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}

static void sig_winch(int signo)
{
    printf("SIGWINCH received\n");
    pr_winsize(STDIN_FILENO);
}

int main()
{
    if(isatty(STDIN_FILENO) == 0)
        return -1;

    if(Signal(SIGWINCH, sig_winch) == SIG_ERR)
        err_sys("Signal error");

    pr_winsize(STDIN_FILENO);

    while(1)
        pause();
}
