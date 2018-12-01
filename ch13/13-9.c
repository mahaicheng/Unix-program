/*************************************************************************
        > 文件名: set_cloexec.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月16日 星期三 10时07分50秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

int set_cloexec(int fd) {
  int val;
  if ((val = fcntl(fd, F_GETFD, 0)) < 0) return -1;

  val |= FD_CLOEXEC;

  return fcntl(fd, F_SETFD, val);
}
