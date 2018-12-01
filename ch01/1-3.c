/*************************************************************************
        > 文件名: 1-3.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月03日 星期四 19时57分14秒
 ************************************************************************/

#include <apue.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
  DIR* dp;
  struct dirent* dirp;

  if (argc != 2) err_quit("Usage: %s <directory name>", argv[0]);

  if ((dp = opendir(argv[1])) == NULL) err_sys("can't open %s", argv[1]);

  while ((dirp = readdir(dp)) != NULL) printf("%s\n", dirp->d_name);

  closedir(dp);
}
