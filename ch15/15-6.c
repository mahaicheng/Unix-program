/*************************************************************************
        > 文件名: 15-6.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月19日 星期一 20时50分42秒
 ************************************************************************/

#include <apue.h>
#include <sys/wait.h>

#define DEF_PAGER "/bin/more"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    err_quit("Usage: %s <pathname>");
  }

  FILE* fp;
  if ((fp = fopen(argv[1], "r")) == NULL) err_sys("can't open %s", argv[1]);

  int fd[2];
  if (pipe(fd) < 0) err_sys("pipe error");

  char line[MAXLINE];
  int n;
  char *pager, *argv0;

  pid_t pid;
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid > 0) {
    close(fd[0]);

    while (fgets(line, MAXLINE, fp) != NULL) {
      n = strlen(line);
      if (write(fd[1], line, n) != n) err_sys("write error to pipe");
    }

    if (ferror(fp)) err_sys("fgets error");

    close(fd[1]);

    if (waitpid(pid, NULL, 0) < 0) err_sys("waitpid error");
    exit(0);
  } else {
    close(fd[1]);

    if (fd[0] != STDIN_FILENO) {
      if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
        err_sys("dup2 error to stdin");
      close(fd[0]);
    }

    if ((pager = getenv("PAGER")) == NULL) pager = DEF_PAGER;
    if ((argv0 = strrchr(pager, '/')) != NULL)
      argv0++;
    else
      argv0 = pager;

    if (execl(pager, argv0, (char*)0) < 0) err_sys("execl error for %s", pager);
  }
  exit(0);
}
