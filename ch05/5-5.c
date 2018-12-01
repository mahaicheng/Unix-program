/*************************************************************************
        > 文件名: 5-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 13时40分42秒
 ************************************************************************/

#include <apue.h>

int main() {
  char buf[MAXLINE];

  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (fputs(buf, stdout) == EOF) {
      err_sys("output error");
    }
  }

  if (ferror(stdin)) {
    err_sys("input error");
  }
}
