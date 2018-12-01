/*************************************************************************
        > 文件名: 10-6.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月22日 星期二 22时07分31秒
 ************************************************************************/

#include <apue.h>
#include <sys/wait.h>

static void sig_child(int signo) {
  pid_t pid;
  int status;
  if ((pid = wait(&status)) < 0) err_sys("wait error");
  printf("SIGCHLD received\n");
  printf("pid: %d\n", pid);
}

int main() {
  if (Signal(SIGCHLD, sig_child) == SIG_ERR) err_sys("Signal SIGCHLD error");

  pid_t pid;
  int status;
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    sleep(5);
    _exit(0);
  }

  int i = 1;
  while (1) {
    sleep(1);
    printf("sleep %d seconds\n", i++);
  }
}
