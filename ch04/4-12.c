/*************************************************************************
        > 文件名: 4-12.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月18日 星期五 10时29分55秒
 ************************************************************************/

#include <apue.h>
int main() {
  struct stat statbuf;

  if (stat("foo", &statbuf) < 0) {
    err_sys("stat error for foo");
  }

  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP | S_ISGID)) < 0) {
    err_sys("chmod error for foo");
  }

  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
    err_sys("chmod error for bar");
  }
}
