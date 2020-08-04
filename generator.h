#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QThread>

class Generator : public QThread
{
    Q_OBJECT
public:
    Generator(QObject* parent);
    void run() override;
public:
    QObject* _parent;
};

class task : public QObject
{
    Q_OBJECT
public:
    task(Generator * myThreadManager);
    virtual ~task();
    Generator * _myThreadManager;
    void work();
signals:
    void taskprogress(uint64_t,int);
    void sendstring(QString);
    void sendint(int);
    void senduint64(uint64_t);
    void sendull(uint64_t);
};

#endif // GENERATOR_H
