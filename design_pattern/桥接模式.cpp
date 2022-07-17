#include <iostream>
using namespace std;

class Engine
{
public:
    virtual void installEngine() = 0;
};

class Engine4400cc: public Engine
{
public:
    void installEngine()
    {
        cout << "this is engine 4400 cc, installed" << endl;
    }
};

class Engine4500cc: public Engine
{
public:
    void installEngine()
    {
        cout << "this is engine 4500 cc, installed" << endl;
    }
};

class Car
{
public:
    Car(Engine* engine) // 将Engine关联到Car中
    {
        this->m_engine = engine;
    }

    virtual void installEngine() = 0;
protected:
    Engine* m_engine;
};

class BMW5: public Car
{
public:
    BMW5(Engine* engine): Car(engine)
    {
        ;
    }

    void installEngine()
    {
        m_engine->installEngine();
    }
};

class BMW6: public Car
{
public:
    BMW6(Engine* engine): Car(engine)
    {
        ;
    }

    void installEngine()
    {
        m_engine->installEngine();
    }
};

int main()
{
    Engine* engine = NULL;
    Car* mycar = NULL;

    engine = new Engine4400cc();
    mycar = new BMW5(engine);

    mycar->installEngine();
    delete engine;
    delete mycar;

    engine = new Engine4500cc();
    mycar = new BMW5(engine);

    mycar->installEngine();
    delete engine;
    delete mycar;

    return 0;
}
