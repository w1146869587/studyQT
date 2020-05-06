#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);

    // 创建一个学生对象
    this->st = new Student(this);

    connect(zt,&Teacher::hungry,st,&Student::treat);
    //调用下课了
    classIsOver();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::classIsOver()
{
    // 下课函数，调用后 触发老师饿了的信号
    emit zt->hungry();

}
