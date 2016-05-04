/*************************************************************************
	> 文件名: 8-20.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 14时04分50秒
 ************************************************************************/

#include<apue.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        if(execl("/home/ma/Unix_Program/ch08/testintterp", "testintterp", "myarg1", "MY ARG2", (char*)0) < 0)
        err_sys("execl error");
    }

    if(waitpid(pid, NULL, 0) < 0)
        err_sys("waitpid error");
}
