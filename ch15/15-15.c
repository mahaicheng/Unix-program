/*************************************************************************
        > 文件名: 15-15.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月19日 星期一 22时31分02秒
 ************************************************************************/

#include <apue.h>
#include <sys/wait.h>

int main() {
  char line[MAXLINE];
  FILE* fpin;

  if ((fpin = popen("./myuclc", "r")) == NULL) err_sys("popen error");

  while (1) {
    fputs("promt>", stdout);
    fflush(stdout);
    if (fgets(line, MAXLINE, fpin) == NULL) break;
    if (fputs(line, stdout) == EOF) err_sys("fputs error to pipe");
  }
  if (pclose(fpin) == -1) err_sys("pclose error");
  putchar('\n');
}
