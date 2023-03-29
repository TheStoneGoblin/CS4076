#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

class Food{
protected:
    int calories = 0;
    double price = 0.5;
public:
    virtual int getCalories() = 0;
    int getPrice(){
        return price;
    }
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
        calories = 10;
        return calories;
    }
};

class Cheese : public Food{
public:
    int getCalories() override{
        calories = 20;
        return calories;
    }
};

class Ham : public Food{
public:
    int getCalories() override{
        calories = 15;
        return calories;
    }
};

class Mush : public Food{
public:
    int getCalories() override{
        calories = 12;
        return calories;
    }
};

class Olive : public Food{
public:
    int getCalories() override{
        calories = 9;
        return calories;
    }
};

class Ice : public Food{
public:
    int getCalories() override{
        calories = 100;
        return calories;
    }
};

int totalCalories = 0;
int totalPrice = 0;

class makePizza{
    public:
    //int totalCalories = 0;
    //int totalPrice = 0;
    Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};
    void add(int ing){
        totalCalories += food[ing]->getCalories();
        totalPrice += food[ing]->getPrice();
    }
    int getCals(){
        return totalCalories;
    }
    int getPrice(){
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
    void addPrice(int num){
        totalPrice += num;
    }
};
