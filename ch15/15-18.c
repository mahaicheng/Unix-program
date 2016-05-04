/*************************************************************************
	> 文件名: 15-18.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月25日 星期日 15时07分43秒
 ************************************************************************/

#include<apue.h>

static void sig_pipe(int);      //be implemented later

int main()
{
    int n, fd1[2], fd2[2];
    pid_t pid;
    char line[MAXLINE];

    if(Signal(SIGPIPE, sig_pipe) == SIG_ERR)
        err_sys("Signal error");

    if(pipe(fd1) < 0 || pipe(fd2) < 0)
        err_sys("pipe error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid > 0){
        close(fd1[0]);
        close(fd2[1]);

        while(fgets(line, MAXLINE, stdin) != NULL){
            n = strlen(line);

            if(write(fd1[1], line, n) != n)
                err_sys("write error");
            if((n = read(fd2[0], line, MAXLINE)) < 0)
                err_sys("read error");
            if(n == 0){
                err_msg("child close pipe");
                break;
            }

            line[n] = 0;
            if(fputs(line, stdout) == EOF)
                err_sys("fputs error");
        }

        if(ferror(stdin))
            err_sys("fgets error");

        exit(0);
    }
    else{
        close(fd1[1]);
        close(fd2[0]);

        if(fd1[0] != STDIN_FILENO){
            if(dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO)
                err_sys("dup2 error to stdin");
            close(fd1[0]);
        }
        if(fd2[1] != STDOUT_FILENO){
            if(dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO)
                err_sys("dup2 error");
            close(fd2[1]);
        }

        if(execl("./add2", "add2", (char*)0) < 0)
            err_sys("execl error");
    }
    exit(0);
}

static void sig_pipe(int signo)
{
    printf("SIGPIPE caught\n");
    exit(1);
}
