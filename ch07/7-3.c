/*************************************************************************
	> 文件名: 7-3.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月19日 星期六 16时51分28秒
 ************************************************************************/

#include<apue.h>

void my_exit1(void)
{
    printf("my_exit1 function\n");
}

void my_exit2(void)
{
    printf("my_exit2 function\n");
}

int main()
{
    atexit(my_exit1);
    atexit(my_exit2);
    atexit(my_exit1);
    atexit(my_exit2);

    printf("main is done\n");
}
