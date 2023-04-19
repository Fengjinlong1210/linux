/*************************************************************************
    > File Name: exit.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2023年04月19日 星期三 15时16分29秒
 ************************************************************************/
//这个程序用来测试系统提供的_exit和C库中的exit函数
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i = 12345;
	printf("%d", i);
	sleep(2);
	exit(0);
	return 0;
}

//int main()
//{
//	int i = 12345;
//	printf("%d", i);
//	sleep(2);
//	_exit(0);
//	return 0;
//}
