#ifndef THREADPOOL_HH
#define THREADPOOL_HH

#include <queue>
#include <thread>

class ThreadPool;
class Job;


class Thread
{
  public:
    Thread(ThreadPool* tp);
    void start(Job* job);
    void join();

    void jobFinished();
    //bool operator==(const Thread* rhs);
  private:
    ThreadPool* mTp;
    std::thread* mThread;
};

class ThreadPool
{
  public:
    explicit ThreadPool(int threadCount);
    Thread* getThread();
    void threadReady(Thread* thread);
    void join();
    //private:
    std::deque<Thread*> idleThreads;
    std::deque<Thread*> runningThreads;
};



class Job
{
  public:
    virtual void doJob() = 0;
//  private:
 
    void operator()(Thread* thread)
    {
        doJob();
        thread->jobFinished();
    }
};


class TcpJob : public Job
{
  public:
    void doJob();
};

class PrinterJob : public Job
{
  public:
    void doJob();
};


#endif

