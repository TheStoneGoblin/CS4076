#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

#pragma once

#include <exception>
#include <iostream>
#include <chrono>
#include <ctime>

int calories = 0;

class Foods{};

class Food : public Foods{
protected:
    double price = 0.5;
public:
    virtual int getCalories() = 0;
    double getPrice(){
        return price;
    }
    friend class Corn;
    friend class Cheese;
    friend class Mush;
    friend class Ham;
    friend class Olive;
    friend class Ice;
    ~Food(){}
};

class Corn : public Food{
public:
    int getCalories() override{
        calories = 10;
        int& ref = calories;
        return ref;
    }
    ~Corn(){}
};

class Cheese : public Food{
public:
    int getCalories() override{
        calories = 20;
        return calories;
    }
    ~Cheese(){}
};

class Ham : public Food{
public:
    int getCalories() override{
        calories = 15;
        return calories;
    }
    ~Ham(){}
};

class Mush : public Food{
public:
    int getCalories() override{
        calories = 12;
        return calories;
    }
    ~Mush(){}
};

class Olive : public Food{
public:
    int getCalories() override{
        calories = 9;
        return calories;
    }
    ~Olive(){}
};

class Ice : public Food{
public:
    int getCalories() override{
        calories = 1000;
        return calories;
    }
    ~Ice(){}
};

union idk{
    int a;
    int b;
};

struct timeStruct{
    unsigned int h : 7;
    unsigned int m : 7;
};



namespace nm{
    class makePizza{
    private:
        int totalCalories;
        double totalPrice;
        public:
        makePizza(int totalCalories, double totalPrice) : totalCalories(totalCalories), totalPrice(totalPrice){}

        Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};
        timeStruct time1;

        void add(int ing){
            totalCalories += food[ing]->getCalories();
            totalPrice += food[ing]->getPrice();
        }
        int getCals(){
            union idk idk1;
            idk1.a = 0;
            //I have no idea where to put unions in my code so this will have to do
            //If somebody held a gun to my head and asked me to use unions in a useful way in this specific code I would die

            return totalCalories;
        }
        double getPrice(){
            return totalPrice;
        }
        void setCals(){
            totalCalories = 0;
        }
        void setPrice(){
            totalPrice = 0;
        }
        void addCalls(int num){
            totalCalories += num;
        }
        template<typename T>
        void addPrice(T num) {
        totalPrice += num;
        }

        QString print(){
            //the use of operator overloading
            //QString s = getCals() + " calories ";
            //return s + QString::number(getPrice()) + " price to make";

            auto now = std::chrono::system_clock::now();
            std::time_t now_t = std::chrono::system_clock::to_time_t(now);
            std::tm* now_tm = std::localtime(&now_t);

            int hour = now_tm->tm_hour;
            int minute = now_tm->tm_min + 15;
            if(minute >= 60){
                hour += 1;
                minute -= 60;
            }
            if(hour >= 24){
                hour -= 24;
            }
            time1.h = hour;
            time1.m = minute;

            return QString::number(getCals()) + " calories " + QString::number(getPrice()) + " price to make \n" +
                   "Your meal will be ready at " + QString::number(time1.h) + ":"+ QString::number(time1.m);
        }

        //friend QString& operator<<(QString& out, const makePizza& pizza);

        ~makePizza(){}
    };
};

class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "What is wrong with you? Don't put ice cream on pizza";
    }
};

/*
QString& operator<<(QString& out, nm::makePizza& pizza) {
        out = pizza.print();
        return out;
    }
*/

QString operator+ (const QString s1, int num){
    QString s = QString::number(num) + s1;
    return s;
}
