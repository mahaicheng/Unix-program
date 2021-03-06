/*************************************************************************
        > 文件名: 17-10.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月11日 星期三 15时21分27秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>

#define CLI_PATH "/var/tmp/"
#define CLI_PERM S_IRWXU

int cli_conn(const char* name /*destination address*/) {
  struct sockaddr_un un;
  if (strlen(name) >= sizeof(un.sun_path)) {
    errno = ENAMETOOLONG;
    return -1;
  }

  int fd;
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) return -1;

  memset(&un, 0, sizeof(un));
  un.sun_family = AF_UNIX;
  sprintf(un.sun_path, "%s%05ld", CLI_PATH, (long)getpid());  // source address
  int len = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);

  int rval;
  unlink(un.sun_path);  // in case it already exists
  if (bind(fd, (struct sockaddr*)&un, len) < 0) {
    rval = -2;
    goto errout;
  }

  int do_unlink = 0;
  if (chmod(un.sun_path, CLI_PERM) < 0) {
    rval = -3;
    do_unlink = 1;
    goto errout;
  }

  struct sockaddr_un sun;
  memset(&sun, 0, sizeof(sun));
  sun.sun_family = AF_UNIX;
  strcpy(sun.sun_path, name);
  len = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);

  if (connect(fd, (struct sockaddr*)&sun, len) < 0) {
    rval = -4;
    do_unlink = 1;
    goto errout;
  }
  return fd;

  int err;
errout:
  err = errno;
  close(fd);
  if (do_unlink) {
    unlink(un.sun_path);
  }
  errno = err;
  return rval;
}
