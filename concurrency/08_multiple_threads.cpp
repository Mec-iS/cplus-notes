/*
Thread objects do not have a copy constructor and thus can not be duplicated
*/
#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread #" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main()
{
    // create threads
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 5; ++i)
    {
        // copying thread objects causes a compile error
        /*
        std::thread t(printHello);
        threads.push_back(t);
        */

        // USE A CONSTRUCT  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        // moving thread objects will work
        threads.emplace_back(std::thread(printHello));
        // emplace_back moves, while push_back copies

        // USE A LAMBDA  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        threads.emplace_back([i]() {

            // wait for certain amount of time
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

            // perform work
            std::cout << "Hello from Worker thread #" << i << std::endl;
        });
    }

    // do something in main()
    std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    // call join on all thread objects using a range-based loop
    // for (auto &t : threads)
    //     t.join();

    // this would be better done using _lambdas_  <<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // so to work around compiling error (use of deleted function)
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
     t.join();
    });


    return 0;
}
