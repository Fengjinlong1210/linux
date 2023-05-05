/*************************************************************************
  > File Name: main.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-05-04 10:57:24
 ************************************************************************/
//这个程序设计一个读取文件的命令，模拟cat命令
#include<stdio.h>
#include <stdlib.h>

//int main(int argc, char* argv[])
//{
//    if(argc != 2)
//    {
//        printf("useage: %s filename\n", argv[0]);
//        return 1;
//    }
//
//    FILE* rf = fopen(argv[1], "r");
//    if(rf == NULL)
//    {
//        perror("fopen");
//        return 2;
//    }
//
//    char buffer[64];
//    while(fgets(buffer, sizeof(buffer), rf) != NULL)
//    {
//        printf("%s", buffer);
//    }
//
//    fclose(rf);
//
//    return 0;
//}

int main()
{
    FILE* wf = fopen("log.txt", "w");
    if(!wf)
    {
        perror("fopen");
        return 1;
    }

    int i = 0;
    for(; i < 5; ++i)
    {
        fprintf(wf, "hello, I am writing to a file %d\n", i + 1);
    }

    return 0;
}
