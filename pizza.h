#ifndef PIZZA_H
#define PIZZA_H

#endif // PIZZA_H

int totalCalories = 0;


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

void makePizza(int ing){
    Food* food[6] = {new Cheese(), new Corn(), new Ham(), new Mush(), new Olive(), new Ice()};
    totalCalories += food[ing]->getCalories();
}
