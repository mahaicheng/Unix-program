/*************************************************************************
        > 文件名: 1-8.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月15日 星期二 19时24分34秒
 ************************************************************************/

#include <errno.h>
#include "apue.h"
int main(int argc, char* argv[]) {
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
  errno = ENOENT;
  perror(argv[0]);
}
