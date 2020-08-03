#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSender_clicked();
    void receivemysignal(QString);

signals:
    void sendmysignal(QString);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
