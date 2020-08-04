#include "generator.h"

Generator::Generator(QObject* parent)
{
    _parent=parent;
}


void Generator::run()
{
    task t(this);
    t.work();
}

#include <QApplication>
task::task(Generator * myThreadManager)
{
    _myThreadManager = myThreadManager;
}

task::~task()
{

}

void task::work()
{
    connect(this, SIGNAL(sendstring(QString)), _myThreadManager->_parent, SLOT(receivestring(QString)));
    connect(this, SIGNAL(sendint(int)), _myThreadManager->_parent, SLOT(receiveint(int)));
    connect(this, SIGNAL(senduint64(uint64_t)), _myThreadManager->_parent, SLOT(receiveuint64(uint64_t)));
    connect(this, SIGNAL(sendull(unsigned long long)), _myThreadManager->_parent, SLOT(receiveull(unsigned long long)));


    uint64_t a = 0xfull;
    int b=77;
    emit sendstring(QString("string"));
    emit sendull(a);
    emit senduint64(a);
    emit sendint(b);
    return;
}

