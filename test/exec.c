#include "syscall.h"

int main()
{
    int j;
    j=3;
    Exec("../test/halt.noff");
    Halt(j);
    /*not reached*/
}