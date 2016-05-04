/*************************************************************************
	> 文件名: myuclc.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月19日 星期一 22时27分07秒
 ************************************************************************/

#include<apue.h>
#include<ctype.h>

int main()
{
    int c;

    while((c = getchar()) != EOF){
        if(isupper(c))
            c = tolower(c);
        if(putchar(c) == EOF)
            err_sys("putchar error");
        if(c == '\n')
            fflush(stdout);
    }
}
