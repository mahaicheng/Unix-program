/*************************************************************************
	> 文件名: 8-25.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月20日 星期日 15时30分04秒
 ************************************************************************/

#include<apue.h>

int main()
{
    printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
}