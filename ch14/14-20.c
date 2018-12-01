/*************************************************************************
        > 文件名: 14-20.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月17日 星期六 20时01分59秒
 ************************************************************************/

#include <apue.h>
#include <ctype.h>
#include <fcntl.h>

#define BSZ 4096

unsigned char buf[BSZ];

unsigned char translate(unsigned char c) {
  if (isalpha(c)) {
    if (c >= 'n')
      c -= 13;
    else if (c >= 'a')
      c += 13;
    else if (c >= 'N')
      c -= 13;
    else
      c += 13;
  }
  return c;
}

int main(int argc, char* argv[]) {
  if (argc != 3) err_quit("Usage: %s <infile> <outfile>", argv[0]);

  int ifd = open(argv[1], O_RDONLY);
  if (ifd < 0) err_sys("open %s failed", argv[1]);
  int ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE);
  if (ofd < 0) err_sys("open %s failed", argv[2]);

  int n;
  while ((n = read(ifd, buf, BSZ)) > 0) {
    int i;
    for (i = 0; i < n; ++i) {
      buf[i] = translate(buf[i]);
    }

    int nw;
    if ((nw = write(ofd, buf, n)) != n) {
      if (nw < 0)
        err_sys("write failed");
      else
        err_quit("short write (%d/%d)", nw, n);
    }
  }
  fsync(ofd);
}
