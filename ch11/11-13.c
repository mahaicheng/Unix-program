/*************************************************************************
        > 文件名: 11-13.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月04日 星期日 20时23分18秒
 ************************************************************************/

#include <apue.h>
#include <pthread.h>

int main() {
  pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

  pthread_mutex_lock(&lock);
  printf("mutex is lock\n");

  struct timespec tout;
  struct tm* tmp;
  char buf[64];
  clock_gettime(CLOCK_REALTIME, &tout);
  tmp = localtime(&tout.tv_sec);
  strftime(buf, sizeof(buf), "%r", tmp);
  printf("current time is %s\n", buf);
  tout.tv_sec += 10;

  int err = pthread_mutex_timedlock(&lock, &tout);
  tmp = localtime(&tout.tv_sec);
  strftime(buf, sizeof(buf), "%r", tmp);
  printf("the time is now %s\n", buf);

  if (err == 0)
    printf("mutex locked again\n");
  else
    printf("can't lock mutex again:%s\n", strerror(err));
}
