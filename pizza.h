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
private:
    double price = 0.5;
public:
    virtual int getCalories() = 0;
    virtual double getPrice() = 0;
    friend class Corn;
    friend class Cheese;
    friend class Mush;
    friend class Ham;
    friend class Olive;
    friend class Ice;
/*
 * attempt at operator overloading, can't fit it in anywhere
    int operator+(int num){
        return num + getCalories();
    }
*/

    ~Food(){}
};

class Corn : public Food{
public:
    int getCalories() override{
        calories = 10;
        int& ref = calories;
        return ref;
    }
    double getPrice() override{
        return price;
    }
    ~Corn(){}
};

class Cheese : public Food{
private:
    int* calories1;
public:
    Cheese(int num){
        calories1 = new int;
        *calories1 = num;
    }
    Cheese(const Cheese& other){
        calories1 = other.calories1;
    }

    int getCalories() override{
        return *calories1;
    }
    double getPrice() override{
        return price;
    }
    ~Cheese(){}
};

class Ham : public Food{
public:
    int getCalories() override{
        calories = 15;
        return calories;
    }
    double getPrice() override{
        return price;
    }
    ~Ham(){}
};

class Mush : public Food{
public:
    int getCalories() override{
        calories = 12;
        return calories;
    }
    double getPrice() override{
        return price;
    }
    ~Mush(){}
};

class Olive : public Food{
public:
    int getCalories() override{
        calories = 9;
        return calories;
    }
    double getPrice() override{
        return price;
    }
    ~Olive(){}
};

class Ice : public Food{
public:
    int getCalories() override{
        calories = 1000;
        return calories;
    }
    double getPrice() override{
        return price;
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
    protected:
        int totalCalories;
        double totalPrice;
    public:
        makePizza(int totalCalories, double totalPrice) : totalCalories(totalCalories), totalPrice(totalPrice){}
        makePizza(const makePizza& other){
            totalCalories = other.totalCalories;
            totalPrice = other.totalPrice;
        }

        Food* food[6] = {new Cheese(20), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};
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
        ~makePizza(){}
    };
};

class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "What is wrong with you? Don't put ice cream on pizza";
    }
};
