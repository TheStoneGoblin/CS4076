#include "mainwindow.h"

#include <QApplication>

class Food{
private:
    int calories = 0;
public:
    virtual int getCalories() = 0;
    friend class Corn;
    friend class Cheese;
    friend class Mush;
    friend class Ham;
    friend class Olive;
    friend class Ice;
};

class Corn : public Food{
public:
    int getCalories() override{
        calories = 100;
        return calories;
    }
};

class Cheese : public Food{
public:
    int getCalories() override{
        int calories = 200;
        return calories;
    }
};

class Ham : public Food{
public:
    int getCalories() override{
        calories = 150;
        return calories;
    }
};

class Mush : public Food{
public:
    int getCalories() override{
        calories = 120;
        return calories;
    }
};

class Olive : public Food{
public:
    int getCalories() override{
        calories = 90;
        return calories;
    }
};

class Ice : public Food{
public:
    int getCalories() override{
        calories = 1000;
        return calories;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
