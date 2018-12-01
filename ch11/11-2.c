/*************************************************************************
        > 文件名: 11-2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月24日 星期四 10时24分19秒
 ************************************************************************/

#include <apue.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char* s) {
  pid_t pid;
  pthread_t tid;

  pid = getpid();
  tid = pthread_self();
  printf("%s\tpid = %lu\ttid = %lu (0x%lx) \n", s, (unsigned long)pid,
         (unsigned long)tid, (unsigned long)tid);
}

void* thr_fn(void* arg) { printids("new pthread: "); }

int main() {
  int err = pthread_create(&ntid, NULL, thr_fn, NULL);

  if (err != 0) err_exit(err, "can't create thread");

  printids("main thread: ");
  sleep(1);
}
