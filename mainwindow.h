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

private slots:
    void on_pushButtonSender_clicked();
    void receivemysignal(QString);
    void onGeneratorFinished();

signals:
    void sendmysignal(QString);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
