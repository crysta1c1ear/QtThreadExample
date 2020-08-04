#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "generator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::sendmysignal, this, &MainWindow::receivestring);

//    connect(this, SIGNAL(sendmysignal(QString)), qApp, SLOT(aboutQt()));

    emit sendmysignal(QString("Started"));

    _generator = new Generator(this);
}

MainWindow::~MainWindow()
{
    delete _generator;
    delete ui;
}

void MainWindow::on_pushButtonSender_clicked()
{
    emit sendmysignal(QString("Button pressed"));
    if (!_generator->isRunning())
        _generator->start();
}

void MainWindow::receiveint(int)
{
    ui->labelReceiver->setText(QString("Got an int"));
}

void MainWindow::receiveuint64(uint64_t)
{
    ui->labelReceiver->setText(QString("Got a uint64"));
}

void MainWindow::receiveull(unsigned long long)
{
    ui->labelReceiver->setText(QString("Got unsigned long long"));
}

void MainWindow::receivestring(QString s)
{
    ui->labelReceiver->setText(s);
}

void MainWindow::onGeneratorFinished()
{
    ui->labelReceiver->setText(QString("finished"));
}

void MainWindow::onthreadprogress(uint64_t bb, int count)
{
    ui->labelReceiver->setText(QString("Progress"));
}
