/*************************************************************************
	> 文件名: 4-24.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 13时24分20秒
 ************************************************************************/

#include<apue.h>

int main()
{
    char* ptr;
    size_t size;

    if(chdir("/usr/lib/X11") < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size);

    if((getcwd(ptr, size)) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
}
