/*************************************************************************
        > 文件名: ex16-1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月04日 星期三 21时45分42秒
 ************************************************************************/

#include <ctype.h>
#include <stdio.h>
int main() {
  unsigned int i = 0x04030201;
  unsigned char* p = (unsigned char*)&i;

  if (*p == 0x01)
    printf("little-endian\n");
  else if (*p == 0x04)
    printf("big-endian\n");
  else
    printf("who konws?\n");
}
