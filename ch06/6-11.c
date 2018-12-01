/*************************************************************************
        > 文件名: 6-11.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 15时55分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char buf2[64];

  time_t t;
  time(&t);

  struct tm* tmp = localtime(&t);

  strftime(buf2, 64, "%r, %a %b %d, %Y", tmp);
  printf("%s", buf2);
}
