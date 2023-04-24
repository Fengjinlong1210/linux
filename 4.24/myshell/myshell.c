/*************************************************************************
  > File Name: myshell.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-04-24 21:21:49
 ************************************************************************/
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024
#define ARG 64
#define SEP " "

int spilt(char* cmdstr, char** cmdret)
{
    assert(cmdstr);
    assert(cmdret);
    cmdret[0] = strtok(cmdstr, SEP);
    if(cmdret[0] == NULL) return -1;
    int i = 1;
    while(cmdret[i++] = strtok(NULL, SEP));
    return 0;
}

void DebugPrint(char** cmdret)
{
    int i = 0;
    for(; cmdret[i]; ++i)
    {
        printf("cmdret[%d] = %s\n", i, cmdret[i]);
    }

    if(cmdret[i] == NULL)
    {
        printf("cmdret[%d] = NULL\n", i);
    }    
}

int main()
{
    while(1)
    {
        char commandstr[MAX] = {0};         //用于存储输入的命令
        char* cmdret[ARG] = {NULL};
        printf("[Fjl@VM-centos PATH]# ");   //显示shell
        fflush(stdout);                     //刷新缓冲区
        char* ret =  fgets(commandstr, sizeof(commandstr), stdin);//获取字符串
        assert(ret);
        (void)ret;   //防止release版本把没有使用的ret直接优化掉
        commandstr[strlen(commandstr) - 1] = '\0'; //处理掉fgets自带的\n

        //分割字符串
        int n = spilt(commandstr, cmdret);
        if(n != 0) continue;

        DebugPrint(cmdret);
        //创建子进程
        pid_t id = fork();
        if(id == 0)
        {
            //child
            int ret = execvp(cmdret[0], cmdret);
            printf("ret = %d\n", ret);
        }
        //回收子进程处理结果
        int status = 0;
        waitpid(id, &status, 0);
    }
    return 0;
}
