#include <iostream>
#include "ThreadPool.hh"



int main()
{
    ThreadPool tp(2);

        std::cout << "Idle count: " << tp.idleThreads.size() << std::endl;
    std::cout << "Running count: " << tp.runningThreads.size() << std::endl;

    std::cout << "----------------\n";
    Thread* thread1 = tp.getThread();
    Thread* thread2 = tp.getThread();
    Thread* thread3 = tp.getThread();

    TcpJob* tcpServer = new TcpJob();
    thread1->start(tcpServer);

    PrinterJob* printer = new PrinterJob();
    thread2->start(printer);
 
//    thread3->start();

    std::cout << "Idle count: " << tp.idleThreads.size() << std::endl;
    std::cout << "Running count: " << tp.runningThreads.size() << std::endl;

    thread1->join();

    tp.join();
}
