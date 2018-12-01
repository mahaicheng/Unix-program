/*************************************************************************
        > 文件名: ex8-6.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月20日 星期日 16时31分01秒
 ************************************************************************/

#include <apue.h>

int main() {
  pid_t pid;

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    printf("child pid = %d\n", getpid());
    exit(0);
  }

  printf("parent pid = %d\n", getpid());
  sleep(4);
  system("ps");
}
