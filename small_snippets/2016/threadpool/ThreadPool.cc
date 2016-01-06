#include "ThreadPool.hh"

#include <algorithm>
#include <thread>

// TODO: remove this include!
#include <iostream>


// TcpJob::TcpJob()
// {
// }

void
TcpJob::doJob()
{
    std::cout << "Server job started!\n";
    while(true);
}


void
PrinterJob::doJob()
{
    std::cout << "Printer!!!!\n";
}


// --------------------------------------

Thread::Thread(ThreadPool* tp) : mTp(tp)
{
}

void
Thread::start(Job* job)
{
    // Run run;
    // std::thread t(run);
    //job->doJob();
    //TcpJob tcp;
    mThread = new std::thread(job, this);
}

void
Thread::join()
{
    mThread->join();
}


void
Thread::jobFinished()
{
    mTp->threadReady(this);
}

// bool
// Thread::operator==(const Thread* rhs)
// {
//     return (this == rhs);
// }

// --------------------------------------------------------

ThreadPool::ThreadPool(int threadCount)
{
    for(int i = 0; i < threadCount; ++i)
    {
        std::cout << "Id:" << i << std::endl;
        idleThreads.push_back( new Thread(this) );
    }
}

Thread*
ThreadPool::getThread()
{
    Thread* thread = NULL;

    if (!idleThreads.empty())
    {
        thread = idleThreads.front();
        idleThreads.pop_front();

        runningThreads.push_back(thread);
    }
    else
    {
        std::cout << "Out of thread!\n";
    }

    return thread;
}


void
ThreadPool::threadReady(Thread* thread)
{
    runningThreads.erase(std::remove(runningThreads.begin(), runningThreads.end(), thread));

    idleThreads.push_back(thread);
}

void
ThreadPool::join()
{
    std::cout << "Waiting for threads joining...\n";
    std::deque<Thread*>::iterator it = idleThreads.begin();
    for( it; it != idleThreads.end(); ++it)
    {
        (*it)->join();
    }

    std::deque<Thread*>::iterator it2 = runningThreads.begin();
    for( it2; it2 != idleThreads.end(); ++it2)
    {
        (*it2)->join();
    }
}
