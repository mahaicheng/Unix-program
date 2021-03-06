/*************************************************************************
        > 文件名: err_XXX.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月03日 星期四 19时16分32秒
 ************************************************************************/

#include <errno.h>
#include <stdarg.h>
#include "apue.h"

static void err_doit(int, int, const char*, va_list);

void err_ret(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
}

void err_sys(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
  exit(0);
}

void err_cont(int error, const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, error, fmt, ap);
  va_end(ap);
}

void err_exit(int error, const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, error, fmt, ap);
  va_end(ap);
  exit(1);
}

void err_dump(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
  abort();
  exit(1);
}

void err_msg(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, 0, fmt, ap);
  va_end(ap);
}

void err_quit(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, 0, fmt, ap);
  va_end(ap);
  exit(0);
}

static void err_doit(int errnoflags, int error, const char* fmt, va_list ap) {
  char buf[MAXLINE];

  vsnprintf(buf, MAXLINE - 1, fmt, ap);
  if (errnoflags) {
    snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
             strerror(error));
  }
  strcat(buf, "\n");
  fflush(stdout);
  fputs(buf, stderr);
  fflush(NULL);
}
