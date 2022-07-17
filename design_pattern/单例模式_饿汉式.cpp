#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "constructor of Singleton runs" << endl;
    }

public:
    static Singleton* getInstance()
    {
        return m_singleton;
    }

    static Singleton* freeInstance()
    {
        if (m_singleton != NULL)
        {
            delete m_singleton;
            m_singleton = NULL;
        }
        return m_singleton;
    }

private:
    static Singleton* m_singleton;
};

Singleton* Singleton::m_singleton = new Singleton; //静态成员变量初始化

int main()
{
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    if (p1 == p2)
        cout << "the same object" << endl;
    else
        cout << "not the same object" << endl;

    Singleton::freeInstance();

    return 0;
}
