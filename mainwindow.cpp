#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QPixmap>



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

}


void MainWindow::on_checkBox_2_toggled(bool checked)
{

}


void MainWindow::on_checkBox_3_toggled(bool checked)
{

}


void MainWindow::on_checkBox_4_toggled(bool checked)
{

}


void MainWindow::on_checkBox_5_toggled(bool checked)
{

}


void MainWindow::on_checkBox_6_toggled(bool checked)
{

}


void MainWindow::on_pushButton_clicked()
{

}

