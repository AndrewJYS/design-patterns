#include <iostream>
using namespace std;

class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings: public FlyBehavior
{
public:
    void fly()
    {
        cout << "I am flying" << endl;
    }
};

class FlyNoWay: public FlyBehavior
{
public:
    void fly()
    {
        cout << "I cannot fly" << endl;
    }
};

class QuackBehavior
{
public:
    virtual void quack() = 0;
};

class Quack: public QuackBehavior
{
public:
    void quack()
    {
        cout << "quack, quack, quack" << endl;
    }
};

class MuteQuack: public QuackBehavior
{
public:
    void quack()
    {
        cout << "silence" << endl;
    }
};

class Squeak: public QuackBehavior
{
public:
    void quack()
    {
        cout << "squeak, squeak, squeak" << endl;
    }
};

class Duck
{
public:
    virtual void display() = 0;

    void setFlyBehavior(FlyBehavior* fb)
    {
        m_FlyBehavior = fb;
    }

    void setQuackBehavior(QuackBehavior* qb)
    {
        m_QuackBehavior = qb;
    }

    void performFly()
    {
        m_FlyBehavior->fly();
    }

    void performQuack()
    {
        m_QuackBehavior->quack();
    }

    void swim()
    {
        cout << "All ducks can swim!" << endl;
    }

protected:
    FlyBehavior* m_FlyBehavior;
    QuackBehavior* m_QuackBehavior;
};

class ModelDuck: public Duck
{
public:
    ModelDuck()
    {
        m_FlyBehavior = new FlyNoWay();
        m_QuackBehavior = new Quack();
    }

    void display()
    {
        cout << "I am a model duck" << endl;
    }
};

class MallardDuck: public Duck
{
public:
    MallardDuck()
    {
        m_FlyBehavior = new FlyWithWings();
        m_QuackBehavior = new Quack();
    }

    void display()
    {
        cout << "I am a Mallard duck" << endl;
    }
};

void test_duck()
{
    Duck* model_duck = new ModelDuck();
    model_duck->display(); // I am a model duck
    model_duck->performFly(); // I cannot fly
    model_duck->performQuack(); // quack, quack, quack

    Duck* mallard_duck = new MallardDuck();
    mallard_duck->display(); // I am a Mallard duck
    mallard_duck->performFly(); // I am flying
    mallard_duck->performQuack(); // quack, quack, quack

    delete model_duck;
    delete mallard_duck;
}

int main()
{
    test_duck();

    return 0;
}
