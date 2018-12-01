/*************************************************************************
        > 文件名: 3-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月15日 星期二 20时20分05秒
 ************************************************************************/

#include <fcntl.h>
#include "apue.h"
#define BUFFSIZE 4096

int main() {
  int n;
  char buf[BUFFSIZE];

  set_fl(STDOUT_FILENO, O_SYNC);
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
  }

  if (n < 0) {
    err_sys("read error");
  }
}
