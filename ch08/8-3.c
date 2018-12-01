/*************************************************************************
        > 文件名: 8-3.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 20时10分44秒
 ************************************************************************/

#include <apue.h>

int globvar = 6;

int main() {
  int var = 88;

  printf("before fork\n");

  pid_t pid;
  if ((pid = vfork()) < 0) {
    err_sys("vfork error");
  } else if (pid == 0) {
    ++var;
    ++globvar;
    fclose(stdout);
    _exit(0);
  }

  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
}
