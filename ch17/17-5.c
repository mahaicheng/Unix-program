/*************************************************************************
        > 文件名: 17-5.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月11日 星期三 13时29分25秒
 ************************************************************************/

#include <apue.h>
#include <sys/socket.h>
#include <sys/un.h>

int main() {
  struct sockaddr_un un;
  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, "foo.socket");

  int fd;
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) err_sys("socket failed");

  int size;
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);

  if (bind(fd, (struct sockaddr*)&un, size) < 0) err_sys("bind failed");

  printf("UNIX domain socket bound\n");
}
