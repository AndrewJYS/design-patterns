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

class Factory
{
public:
    Fruit* create(char* p)
    {
        if (strcmp(p, "banbana"))
            return new Banana;
        else if (strcmp(p, "apple"))
            return new Apple;
        else
            cout << "error" << endl;
    }
};

int main()
{
    Factory* f = new Factory();
    Fruit* fruit = NULL;
    fruit = f->create("banana");
    fruit->getFruit();

    return 0;
}
