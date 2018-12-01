/*************************************************************************
        > 文件名: 10-23.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月23日 星期三 22时11分56秒
 ************************************************************************/

#include <apue.h>

volatile sig_atomic_t quitflag;

static void sig_int(int signo) {
  if (signo == SIGINT)
    printf("\ninterrupt\n");
  else if (signo == SIGQUIT)
    quitflag = 1;
}

int main() {
  if (Signal(SIGINT, sig_int) ==
      SIG_ERR)  // Signal() is user-defined implimented by sigaction
    err_sys("signal error");
  if (Signal(SIGQUIT, sig_int) == SIG_ERR) err_sys("signal error");

  sigset_t newmask, oldmask, zeromask;
  sigemptyset(&zeromask);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGQUIT);

  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("sigprocmask error");

  while (quitflag == 0) sigsuspend(&zeromask);  // no signal to be blocked

  quitflag = 0;

  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("sigprocmask error");
}
