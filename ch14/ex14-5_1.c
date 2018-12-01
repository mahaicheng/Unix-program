/*************************************************************************
        > 文件名: ex14-5_1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月17日 星期六 21时31分26秒
 ************************************************************************/

#include <apue.h>
#include <sys/select.h>

void sleep_us(unsigned int nusecs) {
  struct timeval tval;

  tval.tv_sec = nusecs / 1000000;
  tval.tv_usec = nusecs % 1000000;
  select(0, NULL, NULL, NULL, tval);
}
