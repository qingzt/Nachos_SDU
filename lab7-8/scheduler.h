// scheduler.h 
//	Data structures for the thread dispatcher and scheduler.
//	Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "copyright.h"
#include "list.h"
#include "thread.h"

// The following class defines the scheduler/dispatcher abstraction -- 
// the data structures and operations needed to keep track of which 
// thread is running, and which threads are ready but not running.

class Scheduler {
  public:
    Scheduler();			// Initialize list of ready threads 
    ~Scheduler();			// De-allocate ready list

    void ReadyToRun(Thread* thread);	// Thread can be dispatched.
    Thread* FindNextToRun();		// Dequeue first thread on the ready 
					// list, if any, and return thread.
    void Run(Thread* nextThread);	// Cause nextThread to start running
    void Print();			// Print contents of ready list
    List *getTerminatedList(); //返回停止运行的线程
    List *getWaitingList(); //返回等待运行的线程
    void deleteTerminatedThread(int SpaceID); //删除停止运行的线程
    List *getReadyList(); //返回准备运行的线程
    void emptyList(List *list); //清空线程列表
  private:
    List *readyList;  		// queue of threads that are ready to run,
				// but not running
    List *terminatedList; //停止运行的线程
    List *waitingList; //等待运行的线程
};

#endif // SCHEDULER_H
