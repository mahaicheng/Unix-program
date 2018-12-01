/*************************************************************************
        > 文件名: 10-14.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月16日 星期三 10时27分28秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>

void pr_mask(const char* str) {
  sigset_t sigset;
  int errno_save = errno;

  if (sigprocmask(0, NULL, &sigset) < 0) {
    err_ret("sigprocmask error");
  } else {
    printf("%s", str);

    if (sigismember(&sigset, SIGINT)) printf("SIGINT");
    if (sigismember(&sigset, SIGQUIT)) printf("SIGQUIT");
    if (sigismember(&sigset, SIGUSR1)) printf("SIGUSR1");
    if (sigismember(&sigset, SIGALRM)) printf("SIGALRM");

    printf("\n");
  }

  errno = errno_save;
}
