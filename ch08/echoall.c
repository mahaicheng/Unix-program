/*************************************************************************
	> 文件名: echoall.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 14时13分59秒
 ************************************************************************/

#include<apue.h>

int main(int argc, char* argv[])
{
    putchar('\n');

    int i;
    for(i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    putchar('\n');

    extern char** environ;
    char** ptr = environ;
    while(*ptr != NULL)
    {
        printf("%s\n", *ptr);
        ++ptr;
    }
}
