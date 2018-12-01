/*************************************************************************
        > 文件名: 11-16.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月04日 星期日 22时16分17秒
 ************************************************************************/

#include <apue.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

#define NTHR 1
#define NUMNUM 80000000L
#define TNUM (NUMNUM / NTHR)

long nums[NUMNUM];
long snums[NUMNUM];

pthread_barrier_t b;  // this thread barrier control NTHR+1 threads

int complong(const void* arg1, const void* arg2) {
  long lhs = *(long*)arg1;
  long rhs = *(long*)arg2;

  if (lhs == rhs) return 0;
  if (lhs < rhs) return -1;
  return 1;
}

void* thr_fn(void* arg) {
  long idx = (long)arg;
  qsort(&nums[idx], TNUM, sizeof(long), complong);
  pthread_barrier_wait(
      &b);  // finish the task, and then wait for other threads here

  return (void*)0;
}

void merge() {
  long idx[NTHR];
  long i, minidx, sidx, num;

  for (i = 0; i < NTHR; ++i) idx[i] = i * TNUM;
  for (sidx = 0; sidx < NUMNUM; ++sidx) {
    num = LONG_MAX;
    for (i = 0; i < NTHR; ++i) {
      if ((idx[i] < (i + 1) * TNUM) && (nums[idx[i]] < num)) {
        num = nums[idx[i]];
        minidx = i;
      }
    }
    snums[sidx] = nums[idx[minidx]];
    idx[minidx]++;
  }
}

int main() {
  struct timeval start, end;
  long long startusec, endusec;
  double elapsed;
  int err;
  pthread_t tid;

  srandom(1);
  unsigned long i;
  for (i = 0; i < NUMNUM; ++i) {
    nums[i] = random();
  }

  gettimeofday(&start, NULL);
  pthread_barrier_init(&b, NULL, NTHR + 1);
  for (i = 0; i < NTHR; ++i) {
    err = pthread_create(&tid, NULL, thr_fn, (void*)(i * TNUM));
    if (err != 0) err_exit(err, "can't create pthread");
  }
  pthread_barrier_wait(&b);
  merge();
  gettimeofday(&end, NULL);

  startusec = start.tv_sec * 1000000 + start.tv_usec;
  endusec = end.tv_sec * 1000000 + end.tv_usec;
  elapsed = (double)(endusec - startusec) / 1000000.0;
  printf("sort took %.4f seconds\n", elapsed);

  // for(i = 0; i < NUMNUM; ++i)
  //    printf("%ld\n", snums[i]);
}
