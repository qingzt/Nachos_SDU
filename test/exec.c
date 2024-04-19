#include "syscall.h"

int main()
{
    int j;
    j=Exec("../test/halt.noff");
    Join(j);
    Exit(3);
    /*not reached*/
}