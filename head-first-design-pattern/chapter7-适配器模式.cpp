#include <iostream>
using namespace std;

class Duck
{
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck: public Duck
{
public:
    void quack()
    {
        cout << "Quack!" << endl;
    }

    void fly()
    {
        cout << "I am flying" << endl;
    }
};

class Turkey
{
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey: public Turkey
{
public:
    void gobble()
    {
        cout << "Gobble!" << endl;
    }

    void fly()
    {
        cout << "I am flying a short distance" << endl;
    }
};

class TurkeyAdapter: public Duck //可以把turkey适配到duck，客户使用duck时，实际在使用turkey的属性
{
public:
    TurkeyAdapter(Turkey* t)
    {
        m_turkey = t;
    }

    void quack()
    {
        m_turkey->gobble();
    }

    void fly()
    {
        for (int i = 0; i < 5; ++i)
        {
            m_turkey->fly();
        }
    }

private:
    Turkey* m_turkey;
};

void test()
{
    Duck* duck = new MallardDuck();
    Turkey* turkey = new WildTurkey();
    TurkeyAdapter* ta = new TurkeyAdapter(turkey);

    ta->quack();
    ta->fly();

    delete ta;
    delete turkey;
    delete duck;

    /*
    Gobble!
    I am flying a short distance
    I am flying a short distance
    I am flying a short distance
    I am flying a short distance
    I am flying a short distance
    */
}

int main()
{
    test();

    return 0;
}
