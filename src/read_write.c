/*************************************************************************
	> 文件名: 14-24.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月16日 星期三 12时26分46秒
 ************************************************************************/

#include<apue.h>

ssize_t readn(int fd, void* ptr, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    while(nleft > 0){
        if((nread = read(fd, ptr, nleft)) < 0){
            if(nleft == n)
                return -1;
            else
                break;
        }
        else if(nread == 0){
            break;
        }
        nleft -= nread;
        ptr += nread;
    }
    return n - nleft;
}

ssize_t writen(int fd, const void* ptr, size_t n)
{
    size_t nleft = n;
    ssize_t nwritten;
    while(nleft > 0){
        if((nwritten = write(fd, ptr, nleft)) < 0){
            if(nleft == n)
                return -1;
            else
                break;
        }
        else if(nwritten == 0){
            break;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n - nleft;
}
