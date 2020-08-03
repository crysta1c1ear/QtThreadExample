Qt Thread Examples
==================

This project contains a simple Qt program to start two Qt threads and perform a couple of tasks in each thread.

It prints the identity of each thread a few times, so that you can see which functions run inside which threads and verify for yourself that there truly are multiple threads.


Typical output
--------------
    000001F4B1773F70 Main
    000001F4B1773F70 WorkerThread 1 running 000000AB7EEFFA58
    000001F4B1773F70 WorkerThread 2 running 000000AB7EEFFA40
    000000AB7EEFFA58 Task 1 (running in thread 1)
    000000AB7EEFFA40 Task 1 (running in thread 2)
    000000AB7EEFFA58 Task 2 (running in thread 1)
    000000AB7EEFFA40 Task 2 (running in thread 2)

