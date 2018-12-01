/*************************************************************************
        > 文件名: 8-1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 19时31分09秒
 ************************************************************************/

#include <apue.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main() {
  if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    err_sys("write error");

  fprintf(stderr, "before fork\n");

  int var;
  pid_t pid;
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    globvar++;
    var++;
    printf("child process:\n");
  } else {
    sleep(1);
    printf("parent process:\n");
  }

  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
}
