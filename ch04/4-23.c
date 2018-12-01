/*************************************************************************
        > 文件名: 4-23.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月18日 星期五 13时10分07秒
 ************************************************************************/

#include <apue.h>

int main() {
  if (chdir("/home/ma/Unix_Program") < 0) {
    err_sys("chdir error");
  }

  if (symlinkat("4-12.c", AT_FDCWD, "./ch04/4-12.c.link") < 0) {
    err_sys("symlink error for 4-12.c");
  }
}
