/*************************************************************************
        > 文件名: 3-1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月15日 星期二 19时56分57秒
 ************************************************************************/

#include "apue.h"

int main() {
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    printf("connot seek\n");
  } else {
    printf("seek on\n");
  }
}
