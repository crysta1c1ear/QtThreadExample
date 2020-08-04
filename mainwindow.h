#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "generator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Generator * _generator;

public slots:
    void on_pushButtonSender_clicked();
    void receivestring(QString);
    void receiveint(int);
    void receiveuint64(uint64_t);
    void receiveull(unsigned long long);
    void onGeneratorFinished();
    void onthreadprogress(uint64_t,int);

signals:
    void sendmysignal(QString);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
