/*************************************************************************
        > 文件名: 14-9.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月14日 星期三 20时18分01秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

int lockfile(int fd) {
  struct flock fl;

  fl.l_type = F_WRLCK;
  fl.l_start = 0;
  fl.l_whence = SEEK_SET;
  fl.l_len = 0;
  return fcntl(fd, F_SETLK, &fl);
}
