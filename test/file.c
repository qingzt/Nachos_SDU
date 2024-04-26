#include "syscall.h"

int
main()
{
    int fd,readnum;
    char buffer[10];
    Create("fileTest.txt");
    fd=Open("fileTest.txt");
    Write("1234",4,fd);
    readnum=Read(buffer,4,fd);
    Close(fd);
    Exit(readnum);
}