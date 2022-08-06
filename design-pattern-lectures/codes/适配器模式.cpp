#include <iostream>
using namespace std;

class Current18v
{ // 客户希望用的接口
public:
    virtual void useCurrent18v() = 0;
};

class Current220v
{ // 目前有的接口
public:
    void useCurrent220v()
    {
        cout << "current: 220V" << endl;
    }
};

class Adapter: public Current18v
{ // 将220V适配成18V，接口useCurrent18v()就可以留给客户使用了
public:
    Adapter(Current220v* c)
    {
        m_current = c;
    }
    void useCurrent18v()
    {
        cout << "use adapter to convert 220v to 18v" << endl;
        m_current->useCurrent220v();
    }
private:
    Current220v* m_current;
};

int main()
{
    Current220v* c220 = NULL;
    Adapter* adapter = NULL;

    c220 = new Current220v;
    adapter = new Adapter(c220);
    adapter->useCurrent18v();

    delete c220;
    delete adapter;

    return 0;
}
