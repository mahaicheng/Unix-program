/*************************************************************************
	> 文件名: 8-24.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 15时24分03秒
 ************************************************************************/

#include<apue.h>

int main(int argc, char* argv[])
{
    int status;

    if(argc != 2)
        err_quit("commond-line argument required");

    if((status = system(argv[1])) < 0)
        err_sys("system error");

    pr_exit(status);
}
