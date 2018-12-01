/*************************************************************************
        > 文件名: ex11-1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月05日 星期一 13时13分03秒
 ************************************************************************/

#include <apue.h>
#include <pthread.h>

struct foo {
  int a, b, c, d;
};

void printffoo(const char* s, const struct foo* fp) {
  fputs(s, stdout);
  printf("structure at 0x%lx\n", (unsigned long)fp);
  printf("\tfoo.a = %d\n", fp->a);
  printf("\tfoo.b = %d\n", fp->b);
  printf("\tfoo.c = %d\n", fp->c);
  printf("\tfoo.d = %d\n", fp->d);
}

void* thr_fn(void* arg) {
  struct foo* fp;
  fp = malloc(sizeof(struct foo));
  fp->a = 1;
  fp->b = 2;
  fp->c = 3;
  fp->d = 4;
  printffoo("thread: \n", fp);
  return (void*)fp;
}

int main() {
  pthread_t tid;
  struct foo* fp;

  pthread_create(&tid, NULL, thr_fn, NULL);
  pthread_join(tid, (void*)&fp);
  printffoo("main:\n", fp);
}
