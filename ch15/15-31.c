/*************************************************************************
        > 文件名: 15-31.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月26日 星期一 16时39分58秒
 ************************************************************************/

#include <apue.h>
#include <sys/shm.h>

#define ARRAY_SIZE 40000
#define MALLOC_SIZE 100000
#define SHM_SIZE 100000
#define SHM_MODE 0600  // user read/write

char array[ARRAY_SIZE];

int main() {
  int shmid;
  typedef char* pchar;
  pchar ptr, shmptr;

  printf("array[] from %p to %p\n", &array[0], &array[ARRAY_SIZE]);

  if ((ptr = malloc(MALLOC_SIZE)) == NULL) err_sys("malloc error");
  printf("malloced from %p to %p\n", ptr, (ptr + MALLOC_SIZE));

  if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)
    err_sys("shmget error");
  if ((shmptr = shmat(shmid, 0, 0)) == (void*)-1) err_sys("shmat error");
  printf("shared memory attached from %p to %p\n", shmptr, shmptr + SHM_SIZE);

  if (shmctl(shmid, IPC_RMID, 0) < 0) err_sys("shmctl error");
}
