#include <iostream>
using namespace std;

class Fruit
{
public:
    virtual void getFruit() = 0;
};

class AbstractFactory
{
public:
    virtual Fruit* CreateBanana() = 0;
    virtual Fruit* CreateApple() = 0;
};

class ChineseApple: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a Chinese apple" <<endl;
    }
};

class ThailandApple: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a Thailand apple" <<endl;
    }
};

class ChineseBanana: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a Chinese banana" <<endl;
    }
};

class ThailandBanana: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a Thailand banana" <<endl;
    }
};

class ChineseFactory: public AbstractFactory
{
public:
    Fruit* CreateApple()
    {
        return new ChineseApple;
    }
    Fruit* CreateBanana()
    {
        return new ChineseBanana;
    }
};

class ThailandFactory: public AbstractFactory
{
public:
    Fruit* CreateApple()
    {
        return new ThailandApple;
    }
    Fruit* CreateBanana()
    {
        return new ThailandBanana;
    }
};

int main()
{
    AbstractFactory* af = NULL;
    Fruit* fruit = NULL;

    af = new ChineseFactory();
    fruit = af->CreateApple();
    fruit->getFruit();

    delete fruit;
    fruit = af->CreateBanana();
    fruit->getFruit();
    delete fruit;
    delete af;

    //--------------------------
    af = new ThailandFactory();
    fruit = af->CreateApple();
    fruit->getFruit();

    delete fruit;
    fruit = af->CreateBanana();
    fruit->getFruit();
    delete fruit;
    delete af;

    return 0;
}
