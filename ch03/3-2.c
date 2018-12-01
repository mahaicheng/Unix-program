/*************************************************************************
        > 文件名: 3-2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月15日 星期二 20时01分21秒
 ************************************************************************/

#include <fcntl.h>
#include "apue.h"
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
  int fd;
  if ((fd = creat("file.hole", FILE_MODE)) < 0) {
    err_sys("creat error");
  }

  if (write(fd, buf1, strlen(buf1)) != strlen(buf1)) {
    err_sys("buf1 write error");
  }

  if (lseek(fd, 16384, SEEK_SET) == -1) {
    err_sys("lseek error");
  }

  if (write(fd, buf2, strlen(buf2)) != strlen(buf2)) {
    err_sys("buf2 write error");
  }
}
