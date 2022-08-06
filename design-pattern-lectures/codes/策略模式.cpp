#include <iostream>
using namespace std;

class Strategy
{
public:
    virtual void crypt() = 0;
};

class DES: public Strategy
{
    void crypt()
    {
        cout << "DES cryption" << endl;
    }
};

class AES: public Strategy
{
    void crypt()
    {
        cout << "AES cryption" << endl;
    }
};

class Context
{
public:
    void setStrategy(Strategy* strategy)
    {
        this->m_strategy = strategy;
    }

    void operate()
    {
        m_strategy->crypt();
    }
private:
    Strategy* m_strategy;
};

int main()
{
    Strategy* strategy = NULL;
    Context* context = NULL;

    strategy = new DES;
    context = new Context;
    context->setStrategy(strategy);
    context->operate();

    delete strategy;
    delete context;

    strategy = new AES;
    context = new Context;
    context->setStrategy(strategy);
    context->operate();

    return 0;
}
