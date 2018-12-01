/*************************************************************************
        > 文件名: 16-17.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月04日 星期三 20时25分33秒
 ************************************************************************/

#include <apue.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <syslog.h>

#define BUFLEN 128
#define QLEN 10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

int initserver(int type, const struct sockaddr* addr, socklen_t alen,
               int qlen) {
  int fd;
  int err = 0;

  if ((fd = socket(addr->sa_family, type, 0)) < 0) return -1;

  if (bind(fd, addr, alen) < 0) goto errout;

  if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
    if (listen(fd, qlen) < 0) goto errout;
  }
  return fd;

errout:
  err = errno;
  close(fd);
  errno = err;
  return -1;
}

void serve(int sockfd) {
  set_cloexec(sockfd);

  int clfd;
  FILE* fp;
  char buf[BUFLEN];

  while (1) {
    if ((clfd = accept(sockfd, NULL, NULL)) < 0) {
      syslog(LOG_ERR, "ruptimed: accept error: %s", strerror(errno));
      exit(1);
    }
    set_cloexec(clfd);

    if ((fp = popen("/usr/bin/uptime", "r")) == NULL) {
      sprintf(buf, "error: %s\n", strerror(errno));
      send(clfd, buf, strlen(buf), 0);
    } else {
      while (fgets(buf, BUFLEN, fp) != NULL) send(clfd, buf, strlen(buf), 0);
      pclose(fp);
    }
    close(clfd);
  }
}

int main(int argc, char* argv[]) {
  struct addrinfo *ailist, *aip;
  struct addrinfo hint;
  int sockfd, err, n;
  char* host;

  if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0) n = HOST_NAME_MAX;

  if ((host = malloc(n)) == NULL) err_sys("malloc error");

  if (gethostname(host, n) < 0) err_sys("gethostname error");

  daemonize("ruptimed");
  memset(&hint, 0, sizeof(hint));
  hint.ai_flags = AI_CANONNAME;
  hint.ai_socktype = SOCK_STREAM;
  hint.ai_canonname = NULL;
  hint.ai_addr = NULL;
  hint.ai_next = NULL;

  if (err = getaddrinfo(host, "ruptimed", &hint, &ailist) != 0) {
    syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s", gai_strerror(err));
    exit(1);
  }

  for (aip = ailist; aip != NULL; aip = aip->ai_next) {
    if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr, aip->ai_addrlen,
                             QLEN)) >= 0) {
      serve(sockfd);
      exit(0);
    }
  }
  exit(1);
}
