/*************************************************************************
	> 文件名: open_max.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月16日 星期三 10时00分57秒
 ************************************************************************/

#include<apue.h>
#include<errno.h>
#include<limits.h>

#ifdef OPEN_MAX
    static long openmax = OPEN_MAX;
#else
    static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

long open_max(void)
{
    if(openmax == 0){
        errno = 0;
        if((openmax = sysconf(_SC_OPEN_MAX)) < 0){
            if(errno == 0){
                openmax = OPEN_MAX_GUESS;
            }
            else{
                err_sys("sysconf error for _SC_OPEN_MAX");
            }
        }
    }
    return openmax;
}
