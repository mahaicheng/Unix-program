/*************************************************************************
        > 文件名: 5-4.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 13时35分44秒
 ************************************************************************/

#include <apue.h>

int main(void) {
  int c;
  while ((c = fgetc(stdin)) != EOF) {
    if (fputc(c, stdout) == EOF) {
      err_sys("output error");
    }
  }

  if (ferror(stdin)) {
    err_sys("input error");
  }
}
