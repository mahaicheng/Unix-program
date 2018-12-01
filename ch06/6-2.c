/*************************************************************************
        > 文件名: 6-2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月19日 星期六 15时04分47秒
 ************************************************************************/

#include <pwd.h>
#include <stdio.h>
#include <string.h>

struct passwd* Getpwnam(const char* name) {
  setpwent();
  struct passwd* ptr = NULL;
  while ((ptr = getpwent()) != NULL)
    if (strcmp(name, ptr->pw_name) == 0) break;
  endpwent();
  return ptr;
}

int main() {
  struct passwd* ptr = Getpwnam("ma");
  printf("UID: %d\tGID: %d\n", ptr->pw_uid, ptr->pw_gid);
}
