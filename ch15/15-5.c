/*************************************************************************
        > 文件名: 15-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月17日 星期六 22时44分58秒
 ************************************************************************/

#include <apue.h>
#include <sys/stat.h>

int main() {
  int fd[2];
  if (pipe(fd) < 0) err_sys("pipe error");

  pid_t pid;
  int n;
  char buf[MAXLINE];

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    close(fd[1]);
    n = read(fd[0], buf, MAXLINE);
    write(STDOUT_FILENO, buf, n);
  } else {
    close(fd[0]);
    sleep(1);
    write(fd[1], "Hello Child!\n", 13);
  }
}
