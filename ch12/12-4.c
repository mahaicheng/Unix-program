/*************************************************************************
        > 文件名: 12-4.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月13日 星期二 10时54分15秒
 ************************************************************************/

#include <apue.h>
#include <pthread.h>

int makethread(void* (*fn)(void*), void* arg) {
  int err;
  pthread_t tid;
  pthread_attr_t attr;

  err = pthread_attr_init(&attr);
  if (err != 0) return err;
  err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if (err == 0) err = pthread_create(&tid, &attr, fn, arg);
  pthread_attr_destroy(&attr);
  return err;
}
