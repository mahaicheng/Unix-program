/*************************************************************************
        > 文件名: 1-7.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月15日 星期二 18时58分16秒
 ************************************************************************/

#include <sys/wait.h>
#include "apue.h"

int main() {
  printf("%%");

  char buf[MAXLINE];
  int status;
  pid_t pid;

  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }
    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, (char*)0);
      err_ret("conldn't execute: %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%%");
  }
}
