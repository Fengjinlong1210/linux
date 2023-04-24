/*************************************************************************
  > File Name: proc.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-04-24 09:20:04
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FUNC_NUM 10

typedef void (*func_t)();

func_t Task_List[FUNC_NUM] = {NULL};

void InitTask()
{
    int i = 0;
    for(i = 0; i < FUNC_NUM; ++i)
    {
        Task_List[i] = NULL;
    }

}

void LoadTask(func_t func)
{
    int i = 0;
    for(i = 0; i < FUNC_NUM; ++i)
    {
        if(Task_List[i] == NULL)
        {
            break;
        }
    }
    if(i == FUNC_NUM - 1)
    {
        return;
    }
    else
    {
        Task_List[i] = func;
    }
}

void RunTask()
{
    int i = 0;
    for(i = 0; i < FUNC_NUM; ++i)
    {
        if(Task_List[i] == NULL)
        {
            continue;
        }
        Task_List[i]();
    }
}

void Func1()
{
    printf("这是我运行的程序1\n");
}

void Func2()
{
    printf("这是我运行的程序2\n");
}

void Func3()
{
    printf("这是我运行的程序3\n");
}

int main()
{
    LoadTask(Func1);
    LoadTask(Func2);
    LoadTask(Func3);
    pid_t id = fork();
    if(id < 0)
    {
        printf("error\n");
    }
    else if(id == 0)
    {
        //子进程
        int cnt = 50;
        while(cnt--)
        {
            printf("我是子进程，pid:%d, ppid:%d\n", getpid(), getppid());
            sleep(1);
        }
        exit(0);
    }
    else
    {
        //父进程
        while(1)
        {
            InitTask();
            int status = 0;
            pid_t retid = waitpid(id, &status, WNOHANG);
            if(retid < 0)
                printf("wait error\n");

            else if(retid == 0)
            {
                printf("子进程正在继续，我在执行其他任务\n");
                sleep(1);
                RunTask();
            }
            else
            {
                printf("我是父进程，子进程等待成功，pid:%d, ppid:%d, ret id:%d, 退出码:%d, 退出信号:%d\n",
                        getpid(), getppid(), retid, (status>>8)&0xFF, status&0x7F);
                break;
            }
        }
    }
    return 0;
}
