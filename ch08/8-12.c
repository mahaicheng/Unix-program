/*************************************************************************
        > 文件名: 8-12.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月20日 星期日 11时16分54秒
 ************************************************************************/

#include <apue.h>

static void charatatime(const char* str);

int main() {
  pid_t pid;
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    charatatime("output from child\n");
  } else {
    charatatime("output from parent\n");
  }
}

void charatatime(const char* str) {
  const char* ptr = str;
  int c;
  setbuf(stdout, NULL);
  while ((c = *ptr++) != 0) putc(c, stdout);
}
