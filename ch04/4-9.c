/*************************************************************************
	> 文件名: 4-9.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 10时14分46秒
 ************************************************************************/

#include<apue.h>
#include<fcntl.h>
#include<sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main()
{
    umask(RWRWRW);
    if(creat("foo", RWRWRW) < 0){
        err_sys("creat error for foo");
    }

    umask(S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH);
    if(creat("bar", RWRWRW) < 0){
        err_sys("creat error for bar");
    }
    return 0;
}
