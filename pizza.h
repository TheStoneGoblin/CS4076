#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

#pragma once

#include <exception>
#include <iostream>

class Foods{};

class Food : public Foods{
protected:
    int calories = 0;
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
        calories = 100;
        return calories;
    }
    ~Ice(){}
};

int totalCalories = 0;
double totalPrice = 0;

union idk{
    int a;
    int b;
};

namespace nm{
    class makePizza{
        public:
        Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};

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

        ~makePizza(){}
    };
};
