/*************************************************************************
        > 文件名: 10-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月22日 星期二 21时37分59秒
 ************************************************************************/

#include <apue.h>
#include <pwd.h>
static void my_alarm(int signo) {
  struct passwd* rootptr;

  printf("in Signal handler\n");

  if ((rootptr = getpwnam("root")) == NULL) err_sys("getpwnam error");
  printf("exit my_alarm\n");

  alarm(2);
}

int main() {
  alarm(5);
  Signal(SIGALRM, my_alarm);
  while (1) {
    sleep(1);
    struct passwd* ptr;
    if ((ptr = getpwnam("ma")) == NULL) err_sys("getpwnam ma error");
    if (strcmp(ptr->pw_name, "ma") != 0)
      printf("return value, corrupted!, pw_name = %s\n", ptr->pw_name);
  }
}
