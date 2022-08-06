#include <iostream>
using namespace std;

class Context
{
public:
    Context(int num)
    {
        this->m_num = num;
        this->m_res = num;
    }

    int getNum()
    {
        return m_num;
    }

    void setNum(int num)
    {
        this->m_num = num;
    }

    int getRes()
    {
        return m_res;
    }

    void setRes(int res)
    {
        this->m_res = res;
    }

    void printT()
    {
        cout << "m_num: " << m_num << "; m_res: " << m_res << endl;
    }

private:
    int m_num;
    int m_res;
};

class Expression
{
public:
    virtual void interpret(Context* cocntext) = 0;
};

class AddExpression: public Expression
{
public:
    void interpret(Context* context)
    {
        int num = context->getNum();
        num++;
        context->setNum(num);
        context->setRes(num);
    }
};

class SubtractExpression: public Expression
{
public:
    void interpret(Context* context)
    {
        int num = context->getNum();
        num--;
        context->setNum(num);
        context->setRes(num);
    }
};

int main()
{
    Expression* add = new AddExpression;
    Expression* sub = new SubtractExpression;
    Context* context = new Context(5);

    context->printT();
    add->interpret(context);
    context->printT();
    add->interpret(context);
    context->printT();
    sub->interpret(context);
    context->printT();

    return 0;
}
