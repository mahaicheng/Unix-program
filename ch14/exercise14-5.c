/*************************************************************************
        > 文件名: exercise14-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月16日 星期三 11时13分11秒
 ************************************************************************/

#include <apue.h>
#include <sys/select.h>

void sleep_us(unsigned int nusecs) {
  struct timeval tval;

  tval.tv - sec = nusecs / 1000000;
  tval.tv - usec = nusecs % 1000000;
  select(0, NULL, NULL, NULL, &tval);
}
