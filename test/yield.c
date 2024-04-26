#include "syscall.h"

int main()
{
    int j;
    j=Exec("../test/halt.noff");
    Yield();
    Exit(3);
    /*not reached*/
}