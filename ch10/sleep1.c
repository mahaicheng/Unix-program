/*************************************************************************
	> 文件名: sleep1.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 19时18分33秒
 ************************************************************************/

#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

static void sig_alrm(int signo)
{

}

int main(int argc, char* argv[])
{
    unsigned int seconds;
    if(argc != 2)
        seconds = 1;
    else
        seconds = (unsigned) atoi(argv[1]);

    Signal(SIGALRM, sig_alrm);
    alarm(seconds);
    pause();
}
