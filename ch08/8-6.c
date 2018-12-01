/*************************************************************************
        > 文件名: 8-6.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 21时03分05秒
 ************************************************************************/

#include <apue.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    sleep(1);
    exit(7);
  }

  if (wait(&status) != pid) err_sys("wait error");
  pr_exit(status);

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    sleep(2);
    abort();
  }

  if (wait(&status) != pid) err_sys("wait error");
  pr_exit(status);

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    sleep(3);
    status /= 0;
  }

  if (wait(&status) != pid) err_sys("wait error");
  pr_exit(status);
}
