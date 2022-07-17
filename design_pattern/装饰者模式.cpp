#include <iostream>
using namespace std;

class Car
{
public:
    virtual void show() = 0;
};

class RunCar: public Car
{
public:
    void show()
    {
        cout << "it can run" << endl;
    }
};

class SwimCarDecorator: public Car
{
public:
    SwimCarDecorator(Car* car)
    {
        m_car = car;
    }
    void swim()
    {
        cout << "it can swim" << endl;
    }
    void show()
    {
        m_car->show();
        swim();
    }
private:
    Car* m_car;
};

class FlyCarDecorator: public Car
{
public:
    FlyCarDecorator(Car* car)
    {
        m_car = car;
    }
    void fly()
    {
        cout << "it can fly" << endl;
    }
    void show()
    {
        m_car->show();
        fly();
    }
private:
    Car* m_car;
};

int main()
{
    Car* mycar = NULL;
    mycar = new RunCar;
    mycar->show();
    cout << endl;

    FlyCarDecorator* flycar = new FlyCarDecorator(mycar);
    flycar->show();
    cout << endl;

    SwimCarDecorator* swimcar = new SwimCarDecorator(flycar);
    swimcar->show();

    return 0;
}
