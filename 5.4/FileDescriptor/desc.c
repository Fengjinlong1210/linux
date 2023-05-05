/*************************************************************************
  > File Name: desc.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-05-04 15:16:58
 ************************************************************************/
//这个程序用于测试文件标识符，stdin/stdout/stderr
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//int main()
//{
//    char buffer[1024];
//    ssize_t ret = read(0, buffer, strlen(buffer));
//
//    if(ret > 0)
//    {
//        buffer[ret] = '\0';
//        write(1, buffer, strlen(buffer));
//        write(2, buffer, strlen(buffer));
//    }
//    return 0;
//}


//stdout和stderr都对应显示器输出，stdin对应键盘输入
//int main()
//{
//    printf("printf->stdout\n");
//    fprintf(stdout, "fprintf->stdout\n");
//    fprintf(stderr, "fprintf->stderr\n");
//    return 0;
//}

//输出重定向
//int main()
//{
//    close(1);
//    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
//
//    printf("I am printf\n");
//    printf("I am printf\n");
//    printf("I am printf\n");
//    printf("I am printf\n");
//    printf("I am printf\n");
//    printf("I am printf\n");
//}

//输入重定向
int main()
{
    close(0);
    int fd = open("data.txt", O_RDONLY);

    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
