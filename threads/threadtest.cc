// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

//----------------------------------------------------------------------
//简单线程
//循环 5 次，每次迭代将 CPU 交给另一个就绪线程。
//
//“which”只是一个标识线程的数字，用于调试
//目的。
//----------------------------------------------------------------------

void
SimpleThread(_int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", (int) which, num);
        currentThread->Yield();//SimpleThread函数调用Yield函数，使当前线程让出CPU
    }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1); //通过Fork函数创建一个新的线程，线程名为forked thread，线程号为1
    //通过Fork调用的函数会不先运行，而是加入到就绪队列中
    SimpleThread(0);//调用SimpleThread函数，线程号为0
}

