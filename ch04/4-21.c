/*************************************************************************
	> 文件名: 4-21.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 12时29分36秒
 ************************************************************************/

#include<apue.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];
    for(i = 1; i < argc; ++i){
        if(stat(argv[i], &statbuf) < 0){
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0){
            err_ret("%s: open error", argv[i]);
            continue;
        }

        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;

        if(futimens(fd, times) < 0)
            err_ret("%s: futimens error", argv[i]);
        close(fd);
    }
}
