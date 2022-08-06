#include <iostream>
using namespace std;

class Beverage
{
public:
    virtual double cost() = 0;
    virtual string getDescription() = 0;

protected:
    string m_description;
};

class CondimentDecorator: public Beverage
{
public:
    virtual string getDescription() = 0;

protected:
    Beverage* m_beverage;
};

class Espresso: public Beverage
{
public:
    Espresso()
    {
        m_description = "espresso coffee";
    }

    string getDescription()
    {
        return m_description;
    }

    double cost()
    {
        return 1.99;
    }
};

class HouseBlend: public Beverage
{
public:
    HouseBlend()
    {
        m_description = "house-blend coffee";
    }

    string getDescription()
    {
        return m_description;
    }

    double cost()
    {
        return 0.89;
    }
};

class DarkRoast: public Beverage
{
public:
    DarkRoast()
    {
        m_description = "dark-roast coffee";
    }

    string getDescription()
    {
        return m_description;
    }

    double cost()
    {
        return 1.35;
    }
};

class Decaf: public Beverage
{
public:
    Decaf()
    {
        m_description = "decaf coffee";
    }

    string getDescription()
    {
        return m_description;
    }

    double cost()
    {
        return 0.93;
    }
};

class Mocha: public CondimentDecorator
{
public:
    Mocha(Beverage* b)
    {
        m_beverage = b;
    }

    string getDescription()
    {
        return m_beverage->getDescription() + ", Mocha";
    }

    double cost()
    {
        return m_beverage->cost() + 0.20;
    }
};

class Milk: public CondimentDecorator
{
public:
    Milk(Beverage* b)
    {
        m_beverage = b;
    }

    string getDescription()
    {
        return m_beverage->getDescription() + ", milk";
    }

    double cost()
    {
        return m_beverage->cost() + 0.15;
    }
};

class Soy: public CondimentDecorator
{
public:
    Soy(Beverage* b)
    {
        m_beverage = b;
    }

    string getDescription()
    {
        return m_beverage->getDescription() + ", soy";
    }

    double cost()
    {
        return m_beverage->cost() + 0.11;
    }
};

class Whip: public CondimentDecorator
{
public:
    Whip(Beverage* b)
    {
        m_beverage = b;
    }

    string getDescription()
    {
        return m_beverage->getDescription() + ", whip";
    }

    double cost()
    {
        return m_beverage->cost() + 0.14;
    }
};

void test()
{
    Beverage* espresso = new Espresso();
    cout << espresso->getDescription() << ", cost: " << espresso->cost() << endl;
    // espresso coffee, cost: 1.99

    espresso = new Mocha(espresso);
    cout << espresso->getDescription() << ", cost: " << espresso->cost() << endl;
    // espresso coffee, Mocha, cost: 2.19

    espresso = new Milk(espresso);
    cout << espresso->getDescription() << ", cost: " << espresso->cost() << endl;
    // espresso coffee, Mocha, milk, cost: 2.34

    espresso = new Whip(espresso);
    cout << espresso->getDescription() << ", cost: " << espresso->cost() << endl;
    // espresso coffee, Mocha, milk, whip, cost: 2.48

    delete espresso;
}


int main()
{
    test();

    return 0;
}


/*
class A
{
public:
    virtual string getDescription() = 0;

protected:
    string m_description;
};

class A1: public A
{
public:
    virtual string getDescription() = 0;

protected:
    A* m_a;
};

class A1_concrete1: public A1
{
public:
    A1_concrete1(A* a)
    {
        m_a = a;
    }

    string getDescription()
    {
        return "A1_concrete1";
    }
};

class B: public A
{
public:
    B()
    {
        m_description = "class B";
    }

    string getDescription()
    {
        return m_description;
    }
};

void test_a()
{
    A* b = new B();
    cout << b->getDescription() << endl;

    b = new A1_concrete1(b);
    cout << b->getDescription() << endl;
}
*/
