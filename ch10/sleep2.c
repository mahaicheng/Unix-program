/*************************************************************************
        > 文件名: sleep2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月23日 星期三 19时34分37秒
 ************************************************************************/

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo) { longjmp(env_alrm, 1); }

int main(int argc, char* argv[]) {
  unsigned seconds;
  if (argc != 2)
    seconds = 1;
  else
    seconds = (unsigned)atoi(argv[1]);

  if (signal(SIGALRM, sig_alrm) == SIG_ERR) return -1;

  if (setjmp(env_alrm) == 0) {
    alarm(seconds);
    pause();
  }
  return 0;
}
