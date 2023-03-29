#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

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

namespace nm{
    class makePizza{
        public:
        Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};

        void add(int ing){
            totalCalories += food[ing]->getCalories();
            totalPrice += food[ing]->getPrice();
        }
        int getCals(){
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
