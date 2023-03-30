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

nm::makePizza *pizza = new nm::makePizza;

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

        for(int i = 0; i < ui->label_2->text().toInt(); i++){
            pizza->add(1);
        }
    }
    if (ui->checkBox_2->isChecked()){
        for(int i = 0; i < ui->label->text().toInt(); i++){
            pizza->add(0);
        }
    }
    if (ui->checkBox_3->isChecked()){
        for(int i = 0; i < ui->label_3->text().toInt(); i++){
            pizza->add(2);
        }
    }
    if (ui->checkBox_4->isChecked()){
        for(int i = 0; i < ui->label_4->text().toInt(); i++){
            pizza->add(3);
        }
    }
    if (ui->checkBox_5->isChecked()){
        for(int i = 0; i < ui->label_5->text().toInt(); i++){
            pizza->add(4);
        }
    }
    if (ui->checkBox_6->isChecked()){
        for(int i = 0; i < ui->label_6->text().toInt(); i++){
            pizza->add(5);
        }

        //throw MyException;
    }
    if (ui->radioButton->isChecked()){
        pizza->addPrice(7);
    }
    if (ui->radioButton_2->isChecked()){
        pizza->addPrice(5);
    }
    if (ui->radioButton_3->isChecked()){
        pizza->addPrice(9);
    }
    if (ui->radioButton_4->isChecked()){
        pizza->addPrice(11);
    }

    ui->textEdit->setText(QString::number(pizza->getCals()) + " calories " + QString::number(pizza->getPrice()) + " price to make");
    pizza->setCals();
    pizza->setPrice();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_2->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    ui->label_3->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    ui->label_4->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    ui->label_5->setText(QString::number(value));
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    ui->label_6->setText(QString::number(value));
}


void MainWindow::on_actionQuit_triggered()
{
    delete pizza;
    QCoreApplication::quit();
}
