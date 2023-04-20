/*************************************************************************
    > File Name: main.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 19 Apr 2023 09:30:31 PM CST
 ************************************************************************/
//这个程序用来测试进程等待
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

//int main()
//{
//	//获取子进程的退出状态
//	pid_t id = fork();
//	if(id == 0)
//	{
//		//子进程
//		sleep(10);
//		exit(123);
//	}
//	else
//	{
//		//父进程
//		int status = 0;
//		pid_t ret = wait(&status);
//		if(ret > 0 && (status & 0x7F) == 0)
//		{
//			printf("退出状态:exitcode:%d\n", (status >> 8) & 0xFF);
//		}
//		else if(ret > 0)
//		{
//			printf("异常退出:sigcode:%d\n", status & 0x7F);
//		}
//	}
//	return 0;
//}
//

//进程的阻塞等待

int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		//子进程
		int cnt = 20;
		while(cnt--)
		{
			printf("子进程在运行,pid:%d, ppid:%d\n", getpid(), getppid());
			sleep(1);
		}
		exit(250);
	}
	else
	{
		//父进程
		int status = 0;
		pid_t ret = waitpid(id, &status, 0);//阻塞式等待
		printf("我是父进程，我在等待子进程退出,退出码：%d, 退出信号：%d\n", (status >> 8) & 0xFF, status & 0x7F);
		if(WIFEXITED(status) == 0)
		{
			//异常终止
			printf("子进程异常终止，退出码:%d，退出信号:%d\n", WEXITSTATUS(status), status&0x7F);
		}
		else //正常终止
		{
			printf("子进程正常终止，退出码:%d, 退出信号:%d\n", WEXITSTATUS(status), status&0x7F);
		}
	}

	return 0;
}
