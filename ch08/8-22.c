/*************************************************************************
	> 文件名: 8-22.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 14时55分02秒
 ************************************************************************/

#include<errno.h>
#include<sys/wait.h>
#include<unistd.h>

int System(const char* cmdstring)
{
    pid_t pid;
    int status;

    if(cmdstring == NULL)
        return 1;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        if(execl("/bin/sh", "sh", "-c", cmdstring, (char*)0) < 0)
            err_sys("execl error");
        _Exit(127);
    }
    else{
        while(waitpid(pid, &status, 0) < 0){
            if(errno != EINTR){
                status = -1;
                break;
            }
        }
    }

    return status;
}
