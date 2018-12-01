/*************************************************************************
        > 文件名: 13.1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月29日 星期二 22时28分51秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <syslog.h>

void daemonize(const char* cmd) {
  umask(0);

  struct rlimit rl;
  if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
    err_quit("%s: can not get file limit", cmd);

  pid_t pid;
  if ((pid = fork()) < 0)
    err_quit("%s: can not fork", cmd);
  else if (pid != 0)
    exit(0);

  setsid();

  struct sigaction sa;
  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  if (sigaction(SIGHUP, &sa, NULL) < 0) err_quit("%s: sigaction error", cmd);

  if ((pid = fork()) < 0)
    err_quit("%s: can't fork", cmd);
  else if (pid != 0)
    exit(0);

  if (chdir("/") < 0) err_quit("%s: chdir error");

  if (rl.rlim_max == RLIM_INFINITY) rl.rlim_max = 1024;
  int i;
  for (i = 0; i < rl.rlim_max; ++i) close(i);

  int fd0, fd1, fd2;
  fd0 = open("/dev/null", O_RDWR);
  fd1 = dup(0);
  fd2 = dup(0);

  openlog(cmd, LOG_CONS, LOG_DAEMON);

  if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
    syslog(LOG_ERR, "unexpected file decriptors %d %d %d", fd0, fd1, fd2);
  }
}
