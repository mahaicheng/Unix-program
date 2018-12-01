/*************************************************************************
        > 文件名: 14-1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月13日 星期二 17时27分33秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main() {
  int ntowrite, nwrote;
  char* ptr;

  ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
  fprintf(stderr, "read %d bytes\n", ntowrite);

  set_fl(STDOUT_FILENO, O_NONBLOCK);

  ptr = buf;

  while (ntowrite > 0) {
    errno = 0;
    nwrote = write(STDOUT_FILENO, ptr, ntowrite);
    fprintf(stderr, "nwrote = %d, errno = %d\n", nwrote, errno);

    if (nwrote > 0) {
      ptr += nwrote;
      ntowrite -= nwrote;
    }
  }

  clr_fl(STDOUT_FILENO, O_NONBLOCK);
}
