#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget;

    QPushButton *button1 = new QPushButton("A");
    QPushButton *button2 = new QPushButton("B");
    QPushButton *button3 = new QPushButton("C");
    QPushButton *button4 = new QPushButton("D");
    QPushButton *button5 = new QPushButton("E");
    QPushButton *button6 = new QPushButton("F");

    QLabel *label1 = new QLabel("A");
    QLabel *label2 = new QLabel("B");
    QLabel *label3 = new QLabel("C");
    QLabel *label4 = new QLabel("D");
    QLabel *label5 = new QLabel("E");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 1, 0);
    layout->addWidget(button3, 2, 0);
    layout->addWidget(button4, 3, 0);
    layout->addWidget(button5, 4, 0);
    layout->addWidget(label1, 0, 1);
    layout->addWidget(label2, 1, 1);
    layout->addWidget(label3, 2, 1);
    layout->addWidget(label4, 3, 1);
    layout->addWidget(label5, 4, 1);
    layout->addWidget(button6, 5, 0, 1, 2);

    widget->setLayout(layout);
    widget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

