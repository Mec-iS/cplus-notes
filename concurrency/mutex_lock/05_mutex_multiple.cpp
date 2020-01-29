/*
Multiple mutexes may trigger Type 2 Deadlocks
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// mutexes are acquired and released with the same order, otherwise a deadlock would happen
void ThreadA()
{
    // 1
    mutex1.lock();
    std::cout << "Thread A" << std::endl;
    // 2
    mutex2.lock();

    // 1 & 2
    mutex1.unlock();
    mutex2.unlock();
}

void ThreadB()
{
    // 1
    mutex1.lock();
    std::cout << "Thread B" << std::endl;
    // 2
    mutex2.lock();

    // 1 & 2
    mutex1.unlock();
    mutex2.unlock();
}
// if one of the lock/unlock was ordered differently, a deadlock would happen
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void ExecuteThreads()
{
    std::thread t1( ThreadA );
    std::thread t2( ThreadB );

    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;
}

int main()
{
    ExecuteThreads();

    return 0;
}
