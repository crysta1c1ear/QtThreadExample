#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::sendmysignal, this, &MainWindow::receivemysignal);

    emit sendmysignal(QString("started"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSender_clicked()
{
    emit sendmysignal(QString("button pressed"));
}

void MainWindow::receivemysignal(QString s)
{
    ui->labelReceiver->setText(s);
}
