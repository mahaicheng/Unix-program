/*************************************************************************
	> 文件名: add2.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月19日 星期一 22时49分58秒
 ************************************************************************/

#include<apue.h>

int main()
{
    int n, int1, int2;
    char line[MAXLINE];

    while((n = read(STDIN_FILENO, line, MAXLINE)) > 0)
    {
        line[n] = 0;

        if(sscanf(line, "%d%d", &int1, &int2) == 2)
        {
            sprintf(line, "%d\n", int1+int2);
            n = strlen(line);
            if(write(STDOUT_FILENO, line, n) != n)
            {
                err_sys("write error");
            }
        }
        else
        {
            if(write(STDOUT_FILENO, "invalid args\n", 13) != 13)
            {
                err_sys("write error");
            }
        }
    }
}
