/*************************************************************************
	> 文件名: test.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月19日 星期六 15时40分12秒
 ************************************************************************/

#include<apue.h>
#include<sys/utsname.h>

int main()
{
    char name[MAXLINE];

    if(gethostname(name, sizeof(name)) < 0)
        err_sys("gethostname error");

    printf("the hostname is: %s\n", name);

    struct utsname ptr;
    if(uname(&ptr) < 0)
        err_sys("uname error");

    printf("the hostname is: %s\n", ptr.nodename);
}
