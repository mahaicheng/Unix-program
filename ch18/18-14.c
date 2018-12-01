/*************************************************************************
        > 文件名: 18-14.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月12日 星期四 09时27分55秒
 ************************************************************************/

#include <termios.h>

int main() {
  printf("fd 0: %s\n", isatty(0) ? "tty" : "not a tty");
  printf("fd 1: %s\n", isatty(1) ? "tty" : "not a tty");
  printf("fd 2: %s\n", isatty(2) ? "tty" : "not a tty");
}
