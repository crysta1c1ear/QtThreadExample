Qt Examples
===========
 - Qt Thread Example
 - Qt Signal and Slot Example

Qt Thread Example
=================

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

Qt Signal and Slot Example
==========================

This project contains a simple Qt program to send a SIGNAL and receive it in a SLOT.

A label says "Nothing recieved yet". As soon as the program starts a signal is emited to change the text to "Started". Then a button can be pressed to change the text to "Button Pressed".

The important parts of the program may be found by looking for the Qt symbols

 - emit
 - signal
 - slot
 - connect

and the program symbols
 - sendmysignal
 - receivemysignal
