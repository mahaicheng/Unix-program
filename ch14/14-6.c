/*************************************************************************
        > 文件名: 14-6.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月16日 星期三 11时38分24秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len) {
  struct flock lock;

  lock.l_type = type;
  lock.l_start = offset;
  lock.l_whence = whence;
  lock.l_len = len;

  if (fcntl(fd, F_GETFK, &lock) < 0) err_sys("fcntl error");

  if (lock.l_type == F_UNLCK) return 0;
  return lock.l_pid;
}
