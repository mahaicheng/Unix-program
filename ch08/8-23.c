/*************************************************************************
	> 文件名: 8-23.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 14时52分41秒
 ************************************************************************/

#include<apue.h>
#include"8-22.c"
int main()
{
    int status;
    if((status = System("date")) < 0)
        err_sys("System error");
    pr_exit(status);

    if((status = System("nosuchcommond")) < 0)
        err_sys("System error");
    pr_exit(status);

    if((status = System("who; exit 44")) < 0)
        err_sys("System error");
    pr_exit(status);
}
