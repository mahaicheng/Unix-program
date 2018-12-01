/*************************************************************************
        > 文件名: 14-7.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月14日 星期三 19时47分15秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

static void lockabyte(const char* name, int fd, off_t offset) {
  if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
    err_sys("%s: writew_lock error", name);
  printf("%s: got the lock, byte %lld\n", name, (long long)offset);
}

int main() {
  int fd;
  pid_t pid;

  if ((fd = creat("temp.lock", FILE_MODE)) < 0) err_sys("creat error");
  if (write(fd, "ab", 2) != 2) err_sys("write error");

  tell_wait();
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    lockabyte("child", fd, 0);
    tell_parent(getppid());
    wait_parent();
    lockabyte("child", fd, 1);
  } else {
    lockabyte("parent", fd, 1);
    tell_child(pid);
    wait_child();
    lockabyte("parent", fd, 0);
  }
}
