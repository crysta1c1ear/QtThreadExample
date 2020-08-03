#include <QCoreApplication>
#include <QThread>
#include <QMutex>

#include <iostream>

using namespace std;

static QMutex mymutex; // whole lines of I.E. NOT INTERMIXED LIKE THIS output

class Task : public QObject
{
public:
    Task(int nTask, int nThread)
    {
        QMutexLocker locker(&mymutex);
        cout << this->thread() << " Task " << nTask << " (running in thread " << nThread << ")"<< endl;
    }
};

class WorkerThread : public QThread
{
public:
    int _nThread;
    WorkerThread(int nThread)
    {
        _nThread=nThread;
    }
    void run()
    {
        QObject q;
        {
            QMutexLocker locker(&mymutex);
            cout << this->thread() << " WorkerThread " << _nThread << " running " << q.thread() << endl;
        }
        Task task1(1, _nThread);
        Task task2(2, _nThread);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WorkerThread workerthread1(1);
    cout << a.thread() << " Main" << endl;
    WorkerThread workerthread2(2);
    workerthread1.start();
    workerthread2.start();

    return a.exec();
}

