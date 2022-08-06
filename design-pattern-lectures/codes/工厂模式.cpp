#include <iostream>
#include <string.h>
using namespace std;

class Fruit
{
public:
    virtual void getFruit() = 0;
};

class Banana: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a banana" <<endl;
    }
};

class Apple: public Fruit
{
public:
    void getFruit()
    {
        cout << "get an apple" <<endl;
    }
};

class Pear: public Fruit
{
public:
    void getFruit()
    {
        cout << "get a pear" <<endl;
    }
};

class absFactory
{
public:
    virtual Fruit* create() = 0;
};

class BananaFactory: public absFactory
{
public:
    Fruit* create()
    {
        return new Banana;
    }
};

class AppleFactory: public absFactory
{
public:
    Fruit* create()
    {
        return new Apple;
    }
};

class PearFactory: public absFactory
{
public:
    Fruit* create()
    {
        return new Pear;
    }
};

int main()
{
    absFactory* fac = NULL;
    Fruit* fruit = NULL;

    fac = new BananaFactory();
    fruit = fac->create();
    fruit->getFruit();

    delete fruit;
    delete fac;

    fac = new PearFactory();
    fruit = fac->create();
    fruit->getFruit();

    return 0;
}
