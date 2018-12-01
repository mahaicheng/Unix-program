/*************************************************************************
        > 文件名: log_XXX.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月03日 星期四 19时16分47秒
 ************************************************************************/

#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include "apue.h"

static void log_doit(int, int, int, const char*, va_list);
extern int log_to_stderr;  // defined by user

void log_open(const char* ident, int option, int facility) {
  if (log_to_stderr == 0) openlog(ident, option, facility);
}

void log_ret(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(1, errno, LOG_ERR, fmt, ap);
  va_end(ap);
}

void log_sys(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(1, errno, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(2);
}

void log_msg(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(0, 0, LOG_ERR, fmt, ap);
  va_end(ap);
}

void log_quit(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(0, 0, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(2);
}

void log_exit(int error, const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  log_doit(1, error, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(2);
}

static void log_doit(int errnoflags, int error, int priority, const char* fmt,
                     va_list ap) {
  char buf[MAXLINE];

  vsnprintf(buf, MAXLINE - 1, fmt, ap);
  if (errnoflags)
    snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
             strerror(error));
  strcat(buf, "\n");
  if (log_to_stderr) {
    fflush(stdout);
    fputs(buf, stderr);
    fflush(stderr);
  } else {
    syslog(priority, "%s", buf);
  }
}
