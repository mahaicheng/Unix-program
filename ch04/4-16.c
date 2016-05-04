/*************************************************************************
	> 文件名: 4-16.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 11时07分21秒
 ************************************************************************/

#include<apue.h>
#include<fcntl.h>

int main()
{
    if(open("4-8", O_RDWR) < 0)
        err_sys("open error");

    if(unlink("4-8") < 0)
        err_sys("unlink error");

    printf("file unlink OK\n");

    sleep(20);

    printf("done\n");
}
