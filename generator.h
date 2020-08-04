#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QThread>

class Generator : public QThread
{
    Q_OBJECT
public:
    Generator();
    void run() override;

signals:
};

#endif // GENERATOR_H
