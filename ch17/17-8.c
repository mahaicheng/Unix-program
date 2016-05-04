/*************************************************************************
	> 文件名: 17-8.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月11日 星期三 14时52分07秒
 ************************************************************************/

#include<apue.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<errno.h>

#define QLEN 10

int serv_listen(const char* name)
{
    struct sockaddr_un un;
    if(strlen(name) >= sizeof(un.sun_path)){
        errno = ENAMETOOLONG;
        return -1;
    }

    int fd;
    if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)  //1
        return -2;

    unlink(name);   //in case it already exists

    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, name);
    int len;
    len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

    int rval;
    if(bind(fd, (struct sockaddr*)&un, len) < 0){   //2
        rval = -3;
        goto errout;
    }

    if(listen(fd, QLEN) < 0){   //3
        rval = -4;
        goto errout;
    }

    return fd;

    int err;
errout:
    err = errno;
    close(fd);
    errno = err;
    return rval;
}
