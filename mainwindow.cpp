#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget;

    QCheckBox *button1 = new QCheckBox("Mushroom");
    QCheckBox *button2 = new QCheckBox("Corn");
    QCheckBox *button3 = new QCheckBox("Ham");
    QCheckBox *button4 = new QCheckBox("Olive");
    QCheckBox *button5 = new QCheckBox("Ice Cream");
    QPushButton *button6 = new QPushButton("Make Pizza");

    QButtonGroup *group = new QButtonGroup;
    QRadioButton *radio1 = new QRadioButton("7 inch");
    QRadioButton *radio2 = new QRadioButton("9 inch");
    QRadioButton *radio3 = new QRadioButton("12 inch");
    QRadioButton *radio4 = new QRadioButton("16 inch");
    group->addButton(radio1);
    group->addButton(radio2);
    group->addButton(radio3);
    group->addButton(radio4);

    QLabel *label1 = new QLabel("A");
    QLabel *label2 = new QLabel("B");
    QLabel *label3 = new QLabel("C");
    QLabel *label4 = new QLabel("D");
    QLabel *label5 = new QLabel("E");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1, 0, 0, 1, 2);
    layout->addWidget(button2, 1, 0, 1, 2);
    layout->addWidget(button3, 2, 0, 1, 2);
    layout->addWidget(button4, 3, 0, 1, 2);
    layout->addWidget(button5, 4, 0, 1, 2);

    layout->addWidget(label1, 0, 3, 1, 2);
    layout->addWidget(label2, 1, 3, 1, 2);
    layout->addWidget(label3, 2, 3, 1, 2);
    layout->addWidget(label4, 3, 3, 1, 2);
    layout->addWidget(label5, 4, 3, 1, 2);

    layout->addWidget(radio1, 5, 0);
    layout->addWidget(radio2, 5, 1);
    layout->addWidget(radio3, 5, 2);
    layout->addWidget(radio4, 5, 3);

    layout->addWidget(button6, 6, 0, 1, 4);

    widget->setLayout(layout);
    widget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

