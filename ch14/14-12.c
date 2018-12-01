/*************************************************************************
        > 文件名: 14-12.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月14日 星期三 20时46分22秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[1]);
    exit(1);
  }

  int fd;
  fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE);
  write(fd, "abcdef", 6);

  struct stat statbuf;
  fstat(fd, &statbuf);
  fchmod(fd, (statbuf.st_mode & ~S_IXGRP) | S_ISGID);

  tell_wait();

  pid_t pid;
  pid = fork();

  if (pid > 0) {
    write_lock(fd, 0, SEEK_SET, 0);
    tell_child(pid);
    waitpid(pid, NULL, 0);
  } else {
    wait_parent();
    set_fl(fd, O_NONBLOCK);

    if (read_lock(fd, 0, SEEK_SET, 0) != -1)
      err_sys("child: read_lock successed");
    printf("read_lock of already-locked region returns %d\n", errno);

    lseek(fd, 0, SEEK_SET);

    char buf[5];
    if (read(fd, buf, 2) < 0)
      err_ret("read failed (mandatory locking works)");
    else
      printf("read OK (no mandatory locking), buf = %2.2s\n", buf);
  }
}
