#include "syscall.h"

int main()
{
    int pid;
    pid=Exec("../test/halt.noff");
    Join(pid);
    Exit(1);
    /*not reached*/
}