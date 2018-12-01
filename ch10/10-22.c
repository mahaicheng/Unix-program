/*************************************************************************
        > 文件名: 10-22.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月23日 星期三 21时34分49秒
 ************************************************************************/

#include <apue.h>

static void sig_int(int signo) { pr_mask("\nin sig_int: "); }

int main() {
  pr_mask("program start: ");

  if (signal(SIGINT, sig_int) == SIG_ERR) err_sys("signal (SIGINT) error");

  sigset_t newmask, oldmask, waitmask;

  sigemptyset(&newmask);
  sigaddset(&newmask, SIGINT);
  sigemptyset(&waitmask);
  sigaddset(&waitmask, SIGUSR1);

  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("sigprocmask error");

  pr_mask("in critical region: ");

  sleep(5);

  if (sigsuspend(&oldmask) != -1) err_sys("sigsuspend error");

  pr_mask("after return from sigsuspend: ");

  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("SIG_SETMASK error");

  pr_mask("program exit: ");
}
