/*************************************************************************
	> 文件名: 4-25.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 13时37分16秒
 ************************************************************************/

#include<apue.h>
#include<sys/sysmacros.h>
int main(int argc, char* argv[])
{
    int i;
    struct stat statbuf;

    for(i = 1; i < argc; ++i){
        printf("%s: ", argv[i]);

        if(stat(argv[i], &statbuf) < 0){
            err_sys("stat error");
            continue;
        }

        printf("dev = %d/%d", major(statbuf.st_dev), minor(statbuf.st_dev));
        if(S_ISCHR(statbuf.st_mode) || S_ISBLK(statbuf.st_mode)){
            printf(" (%s) rdev = %d/%d",(S_ISCHR(statbuf.st_mode)) ? "character" : "block", major(statbuf.st_rdev), minor(statbuf.st_rdev));
        }
        printf("\n");
    }
}
