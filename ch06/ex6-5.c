/*************************************************************************
        > 文件名: ex6-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 16时04分09秒
 ************************************************************************/

#include <apue.h>
#include <time.h>

int main() {
  time_t caltime;
  struct tm* ptm;
  char line[MAXLINE];

  caltime = time(NULL);
  ptm = localtime(&caltime);
  strftime(line, MAXLINE, "%a %b %d %X %Z %Y\n", ptm);
  printf("%s", line);
}
