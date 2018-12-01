/*************************************************************************
        > 文件名: 17-12.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月11日 星期三 16时57分16秒
 ************************************************************************/

#include <apue.h>

int send_err(int fd, int errcode, const char* errmsg) {
  int n;
  if ((n = strlen(errmsg)) > 0) {
    if (write(fd, errmsg, n) != n) return -1;
  }

  if (errcode > 0) errcode = -1;

  if (write(fd, &errcode, sizeof(errcode)) < 0) return -1;

  return 0;
}
