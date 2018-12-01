/*************************************************************************
        > 文件名: ex14-5_2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月17日 星期六 21时34分24秒
 ************************************************************************/

#include <poll.h>

void sleep_us(unsigned int nusecs) {
  struct pollfd dummy;
  int timeout;

  if ((timeout = nusecs / 1000) <= 0) timeout = 1;

  poll(&dummy, 0, timeout);
}
