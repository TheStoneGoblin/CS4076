#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

class Food{
protected:
    int calories = 0;
    int price = 2;
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
        calories = 100;
        return calories;
    }
};

class Cheese : public Food{
public:
    int getCalories() override{
        calories = 200;
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

class makePizza{
    public:
    int totalCalories = 0;
    int totalPrice = 0;
    Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};
    void calAdd(int ing){
        totalCalories += food[ing]->getCalories();
        totalPrice += food[ing]->getPrice();
    }
};
