#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "generator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::sendmysignal, this, &MainWindow::receivemysignal);

    emit sendmysignal(QString("Started"));

    _generator = new Generator(this);
    connect(_generator, &Generator::finished, this, &MainWindow::onGeneratorFinished);

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

void MainWindow::receivemysignal(QString s)
{
    ui->labelReceiver->setText(s);
}

void MainWindow::onGeneratorFinished()
{
    ui->labelReceiver->setText(QString("finished"));
}
