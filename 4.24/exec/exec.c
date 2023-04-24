/*************************************************************************
  > File Name: exec.c
  > Author: Fjl
  > Mail: 239383772@qq.com 
  > Created Time: 2023-04-24 16:05:36
 ************************************************************************/
//这个程序用于简单的使用execl进行程序替换
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        //子进程
//        printf("我是子进程, pid:%d, ppid:%d\n", getpid(), getppid());
//        int ret = execl("/usr/bin/ls", "ls", "-a", "-l", NULL);
//        printf("ret = %d\n", ret);
//    }
//    else if(id > 0)
//    {
//        //父进程
//        sleep(5);
//        printf("我是父进程, pid:%d\n", getpid());
//        waitpid(id, NULL, 0);
//    }
//    else
//    {
//        printf("fork error\n");
//    }
//    return 0;
//}
//

//execv
//int main()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        //子进程
//        char* const cmdstr[] = 
//        {
//            "ls",
//            "-a",
//            "-l",
//            NULL
//        };
//        printf("我是子进程\n");
//        int ret = execv("/usr/bin/ls", cmdstr);
//        printf("ret = %d\n", ret);
//        exit(0);
//    }
//    sleep(5);
//    printf("我是父进程\n");
//    waitpid(id, NULL, 0);
//
//    return 0;
//}

//execlp   list+path
//int main()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        //child
//        printf("I am child\n");
//        int ret = execlp("ls", "ls", "-a", "-l", NULL);
//        printf("ret = %d\n, ret");
//        exit(0);
//    }
//    sleep(3);
//    printf("I am father\n");
//
//    return 0;
//}
//

//execvp vector+path
//int main()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        //子进程
//        char* const cmdstr[] = 
//        {
//            "ls",
//            "-a",
//            "-l",
//            NULL
//        };
//        printf("我是子进程\n");
//        int ret = execvp("ls", cmdstr);
//        printf("ret = %d\n", ret);
//        exit(0);
//    }
//    sleep(5);
//    printf("我是父进程\n");
//    waitpid(id, NULL, 0);
//
//    return 0;
//}

//通过exec调用自己写的程序
int main()
{
    extern char** environ;
    pid_t id = fork();
    if(id == 0)
    {
        //child
        char* const myenv[] = 
        {
            "MYENV=YouCanSeeMe",
            NULL
        };
        putenv("MYENV=youcanseeme");//将自定义环境变量放入默认环境变量中
        printf("I am child, pid:%d\n", getpid());

       // int ret = execle("./other", NULL, myenv);//自定义环境变量会覆盖默认环境变量

        int ret = execle("./other", NULL, environ);//自定义环境变量会覆盖默认环境变量
        printf("ret = %d\n", ret);
    }

    sleep(5);
    printf("I am father, pid:%d\n", getpid());
    return 0;
}












