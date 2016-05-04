/*************************************************************************
	> 文件名: 8-8.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 09时55分00秒
 ************************************************************************/

#include<apue.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    if((pid = fork()) < 0)
        err_sys("first fork error");
    else if(pid == 0){
        if((pid = fork()) < 0)
            err_sys("second fork error");
        else if(pid > 0)    //first child
            exit(0);

        //second child
        sleep(2);
        printf("\nsecond child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid)
        err_sys("wait error");
    printf("first child exit\n");
}
