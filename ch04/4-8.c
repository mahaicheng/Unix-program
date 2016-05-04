/*************************************************************************
	> 文件名: 4-8.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月18日 星期五 10时05分03秒
 ************************************************************************/

#include<apue.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
    if(argc != 2){
        printf("usage: %s <pathname>", argv[0]);
        return EXIT_FAILURE;
    }

    if(access(argv[1], R_OK) < 0){
        err_ret("access error for %s", argv[1]);
    }
    else{
        printf("read access OK\n");
    }

    if(open(argv[1], O_RDONLY) < 0)
        err_ret("open error for %s", argv[1]);
    else
        printf("open for reading OK\n");
}
