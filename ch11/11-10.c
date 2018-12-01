/*************************************************************************
        > 文件名: 11-10.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月29日 星期二 21时02分24秒
 ************************************************************************/

#include <pthread.h>
#include <stdlib.h>

struct foo {
  int f_count;  // because foo is heap-based, need reference counter
  pthread_mutex_t f_lock;
  int f_id;
};

struct foo* foo_alloc(int id) {
  struct foo* fp;
  if ((fp = malloc(sizeof(struct foo))) != NULL) {
    fp->f_count = 1;
    fp->f_id = id;
    if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
      free(fp);
      return NULL;
    }
  }
  return fp;
}

void foo_hold(struct foo* fp) {
  pthread_mutex_lock(&fp->f_lock);
  fp->f_count++;
  pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo* fp) {
  pthread_mutex_lock(&fp->f_lock);
  if (--fp->f_count == 0) {
    pthread_mutex_unlock(&fp->f_lock);
    pthread_mutex_destroy(&fp->f_lock);
    free(fp);
  } else {
    pthread_mutex_unlock(&fp->f_lock);
  }
}
