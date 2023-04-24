/*************************************************************************
  > File Name: test.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-04-24 21:56:34
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        char* argv[] = 
        {
            "-a", 
            "-l",
            NULL
        };
        //child
        int ret = execvp("ls", argv);    
        printf("ret = %d\n", ret);
    }
    
    waitpid(id, NULL, 0);

    return 0;
}
