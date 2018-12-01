/*************************************************************************
        > 文件名: 18-18.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月12日 星期四 10时06分56秒
 ************************************************************************/

#include <apue.h>
#include <openssl/md5.h>
#include <termios.h>

int main() {
  char* ptr;

  if ((ptr = getpass("Enter password: ")) == NULL) err_sys("getpass error");

  const char passmd5[] = "2d2daeb23687d57d70e022fca4208c57";
  if (strcmp(passmd5, md5(ptr, strlen(ptr))) == 0) {
    printf("password right\n");
    return 0;
  } else {
    printf("password wrong\n");
    return 0;
  }

  while (*ptr != 0) *ptr++ = 0;
}
