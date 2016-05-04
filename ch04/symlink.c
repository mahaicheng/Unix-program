/*************************************************************************
	> 文件名: symlink.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 11时22分51秒
 ************************************************************************/

#include<apue.h>

int main()
{
    if(symlink("4-8.c", "4-8.c.link") < 0)
        err_sys("make symlink 4-8.c error");

    if(symlinkat("4-12.c", AT_FDCWD, "4-12.c.link") < 0)
        err_sys("make symlink 4-12.c error");
}
