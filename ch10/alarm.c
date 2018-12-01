/*************************************************************************
        > 文件名: alarm.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月22日 星期二 22时55分05秒
 ************************************************************************/

#include <apue.h>

int main() {
  alarm(1800);
  printf(
      "This process will be termined by signal SIGALRM 45200 seconds later\n");
  printf("Just wait for that moment...\n");
  int i = 1800;
  while (1) {
    sleep(1);
    printf("%d\n", i--);
  }
}
