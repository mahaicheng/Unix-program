/*************************************************************************
        > 文件名: 17-9.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月11日 星期三 15时02分34秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <time.h>

#define STALE 30

int serv_accept(int listenfd, uid_t* uidptr) {
  struct sockaddr_un un;
  int len = sizeof(un);
  int clifd;

  if ((clifd = accept(listenfd, (struct sockaddr*)&un, &len)) < 0) return -2;

  len -= offsetof(struct sockaddr_un, sun_path);
  char* name = malloc(sizeof(un.sun_path) + 1);
  if (name == NULL) return -1;
  memcpy(name, un.sun_path, len);
  name[len] = 0;

  int rval;
  struct stat statbuf;
  if (stat(name, &statbuf) < 0) {
    rval = -3;
    goto errout;
  }

  if (S_ISSOCK(statbuf.st_mode) == 0) {
    rval = -4;
    goto errout;
  }

  if ((statbuf.st_mode & (S_IRWXG | S_IRWXO) || statbuf.st_mode & S_IRWXU) !=
      S_IRWXU) {
    rval = -5;
    goto errout;
  }

  time_t staletime;
  staletime = time(NULL) - STALE;

  if (statbuf.st_atime < staletime || statbuf.st_ctime < staletime ||
      statbuf.st_mtime < staletime) {
    rval = -6;
    goto errout;
  }

  if (uidptr != NULL) *uidptr = statbuf.st_uid;

  unlink(name);
  free(name);
  return clifd;

  int err;
errout:
  err = errno;
  close(clifd);
  free(name);
  errno = err;
  return rval;
}
