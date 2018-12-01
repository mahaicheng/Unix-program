/*************************************************************************
        > 文件名: 10-18.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月23日 星期三 21时00分59秒
 ************************************************************************/

#include <apue.h>

Sigfunc* Signal(int signo, Sigfunc* func) {
  struct sigaction act, oact;
  act.sa_handler = func;
  sigemptyset(&act.sa_mask);

  act.sa_flags = 0;
  if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
    act.sa_flags |= SA_INTERRUPT;
#endif
  } else {
    act.sa_flags |= SA_RESTART;
  }

  if (sigaction(signo, &act, &oact) < 0) return (SIG_ERR);

  return act.sa_handler;
}
