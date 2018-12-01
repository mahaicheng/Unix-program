/*************************************************************************
        > 文件名: 3-11.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月16日 星期三 13时32分37秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  if (argc != 2) err_quit("usage: %s <descriptor>\n", argv[0]);

  int val;
  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    err_sys("fcntl error for fd %d\n", atoi(argv[1]));

  switch (val & O_ACCMODE) {
    case O_RDONLY:
      printf("read only");
      break;
    case O_WRONLY:
      printf("write only");
      break;
    case O_RDWR:
      printf("read write");
      break;
    default:
      err_dump("unknown access mode");
  }

  if (val & O_APPEND) printf(", append");
  if (val & O_NONBLOCK) printf(", nonblocking");
  if (val & O_SYNC) printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
  if (val & O_FSYNC) printf(", synchronous writes");
#endif

  putchar('\n');
}
