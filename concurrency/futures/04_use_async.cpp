/*
instead of future-promise, future can be used on its own via `async`.

one of the major differences between std::thread and std::async is that with
 the latter, the system decides wether the associated function should be run
 asynchronously or synchronously.

`std::async` makes it possible to control the amount of concurrency by passing
 an optional launch parameter, which enforces either synchronous or asynchronous
 behavior
*/
#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
}


int main()
{
    // use async to start a task
    double num = 42.0, denom = 2.0;
    std::future<double> ftr = std::async(divideByNumber, num, denom); // <<<<<<<


    // to execute synchronously add the "deferred" specifier  <<<<<<<<<<<<<<<<<<
    // std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);

    // retrieve result within try-catch-block
    try
    {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
