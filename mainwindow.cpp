#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "pizza.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QPixmap>

#include <iostream>
using namespace std;

makePizza *pizza = new makePizza;

QPushButton *push_button;
QCheckBox *check1;
QCheckBox *check2;
QCheckBox *check3;
QCheckBox *check4;
QCheckBox *check5;
QCheckBox *check6;
QRadioButton *radio1;
QRadioButton *radio2;
QRadioButton *radio3;
QRadioButton *radio4;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    check1 = new QCheckBox(this);
    connect(check1, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_toggled(bool)));
}


void MainWindow::on_checkBox_2_toggled(bool checked)
{
    check2 = new QCheckBox(this);
    connect(check2, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_2_toggled(bool)));
}


void MainWindow::on_checkBox_3_toggled(bool checked)
{
    check3 = new QCheckBox(this);
    connect(check3, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_3_toggled(bool)));
}


void MainWindow::on_checkBox_4_toggled(bool checked)
{
    check4 = new QCheckBox(this);
    connect(check4, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_4_toggled(bool)));
}


void MainWindow::on_checkBox_5_toggled(bool checked)
{
    check5 = new QCheckBox(this);
    connect(check5, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_5_toggled(bool)));
}


void MainWindow::on_checkBox_6_toggled(bool checked)
{
    check6 = new QCheckBox(this);
    connect(check6, SIGNAL(toggled(bool)), this, SLOT(on_checkBox_6_toggled(bool)));
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    radio1 = new QRadioButton(this);
    connect(radio1, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled(bool)));
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    radio2 = new QRadioButton(this);
    connect(radio2, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_2_toggled(bool)));
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    radio3 = new QRadioButton(this);
    connect(radio3, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_3_toggled(bool)));
}


void MainWindow::on_radioButton_4_toggled(bool checked)
{
    radio4 = new QRadioButton(this);
    connect(radio4, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_4_toggled(bool)));
}


void MainWindow::on_pushButton_clicked(){
    push_button = new QPushButton(this);
    connect(push_button, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));


    if (ui->checkBox->isChecked()){
        pizza->calAdd(0);
    }
    if (ui->checkBox_2->isChecked()){
        pizza->calAdd(1);
    }
    if (ui->checkBox_3->isChecked()){
        pizza->calAdd(2);
    }
    if (ui->checkBox_4->isChecked()){
        pizza->calAdd(3);
    }
    if (ui->checkBox_5->isChecked()){
        pizza->calAdd(4);
    }
    if (ui->checkBox_6->isChecked()){
        pizza->calAdd(5);
    }

    ui->textEdit->setText(QString::number(pizza->totalCalories) + " calories " + QString::number(pizza->totalPrice) + " price");
    pizza->totalCalories = 0;
    pizza->totalPrice = 0;
}
