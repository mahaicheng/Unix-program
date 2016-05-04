/*************************************************************************
	> 文件名: 8-16.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 12时50分00秒
 ************************************************************************/

#include<apue.h>
#include<sys/wait.h>

char* env_init[] = {"USER=unknown", "PATH=/home/ma/Unix_Program/ch08", NULL};

int main()
{
    pid_t pid;
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        if(execle("/home/ma/Unix_Program/ch08/echoall", "echoall", "myarg1", "MY ARG2", (char*)0, env_init) < 0)
            err_sys("execl error");
    }

    if(waitpid(pid, NULL, 0) < 0)
        err_sys("wait error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        if(execlp("date", "2015", (char*)0) < 0)
            err_sys("execlp error");
    }
}
