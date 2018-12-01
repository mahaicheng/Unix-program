/*************************************************************************
        > 文件名: 10-24.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月23日 星期三 22时38分26秒
 ************************************************************************/

#include <apue.h>

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo) { sigflag = 1; }

void tell_wait() {
  if (Signal(SIGUSR1, sig_usr) == SIG_ERR) err_sys("Signal(SIGUSR1) error");
  if (Signal(SIGUSR2, sig_usr) == SIG_ERR) err_sys("Signal(SIGUSR2) error");

  sigemptyset(&newmask);
  sigemptyset(&zeromask);
  sigaddset(&newmask, SIGUSR1);
  sigaddset(&newmask, SIGUSR2);

  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("sigprocmask error");
}

void tell_parent(pid_t pid)  // use by child
{
  kill(pid, SIGUSR2);
}

void wait_parent(void)  // use by child
{
  while (sigflag == 0) sigsuspend(&zeromask);
  sigflag = 0;

  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("sigprocmask error");
}

void tell_child(pid_t pid) { kill(pid, SIGUSR1); }

void wait_child(void) {
  while (sigflag == 0) sigsuspend(&zeromask);
  sigflag = 0;

  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("sigprocmask error");
}
