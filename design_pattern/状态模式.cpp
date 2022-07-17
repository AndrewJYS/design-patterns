#include <iostream>
using namespace std;

class Worker;

class State
{
public:
    virtual void doSomething(Worker* w) = 0;
};

class Worker
{
public:
    Worker();

    int getHour()
    {
        return m_hour;
    }

    void setHour(int hour)
    {
        m_hour = hour;
    }

    State* getCurrentState()
    {
        return m_currstate;
    }

    void setCurrentState(State* state)
    {
        m_currstate = state;
    }

    void doSomething()
    {
        m_currstate->doSomething(this);
    }

private:
    State* m_currstate;  //对象的当前状态
    int m_hour;
};

class State1: public State
{
public:
    void doSomething(Worker* w);
};

class State2: public State
{
public:
    void doSomething(Worker* w);
};

void State1::doSomething(Worker* w)
{
    if (w->getHour() == 7 || w->getHour() == 8)
    {
        cout << "eat breakfast" << endl;
    }
    else
    {  // 不满足State1，跳转到State2
        delete w->getCurrentState();
        w->setCurrentState(new State2);
        w->getCurrentState()->doSomething(w);
    }
}

void State2::doSomething(Worker* w)
{
    if (w->getHour() == 9 || w->getHour() == 10)
    {
        cout << "at work" << endl;
    }
    else
    {  // 不满足State2，跳转到State1
        delete w->getCurrentState();
        w->setCurrentState(new State1);
        w->getCurrentState()->doSomething(w);
    }
}

Worker::Worker()
{
    m_currstate = new State1;
}

int main()
{
    Worker* w = new Worker;
    w->setHour(7);
    w->doSomething();

    w->setHour(9);
    w->doSomething();

    delete w;

    return 0;
}
