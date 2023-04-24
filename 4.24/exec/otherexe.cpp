#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main()
{
    int i = 0;
    for(; i < 5; ++i)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "I am a other process, pid:" << getpid() << endl;
        cout << (getenv("MYENV")==NULL ? "NULL" : getenv("MYENV"))<< endl;
        cout << (getenv("PATH")==NULL ? "NULL" : getenv("PATH")) << endl;
        sleep(1);
    }
    return 0;
}
