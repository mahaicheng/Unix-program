/*************************************************************************
	> 文件名: 1-5.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月15日 星期二 18时01分43秒
 ************************************************************************/

#include"apue.h"

int main()
{
    int c;
    while((c = getc(stdin)) != EOF){
        if((putc(c, stdout)) == EOF){
            err_sys("write error");
        }
    }

    if(ferror(stdin)){
        err_sys("input error");
    }
}
