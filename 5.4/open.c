/*************************************************************************
  > File Name: open.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-05-04 14:56:19
 ************************************************************************/
//这个程序用来使用系统调用接口open
#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//使用open创建文件
int main()
{
    //只传两个参数，不设置权限，会导致新创建的文件权限异常
    //要打开一个不存在的文件，要使用三个参数的open函数
    //int fd = open("log2.txt", O_WRONLY | O_CREAT | O_TRUNC);
    umask(0);
    int fd = open("log2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);
    char* buffer = "This is a buffer";
    int ret = write(fd, buffer, strlen(buffer));
    if(ret < 0)
    {
        printf("write err\n");
    }
    close(fd);

    return 0;
}
