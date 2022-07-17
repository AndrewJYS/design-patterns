#include <iostream>
using namespace std;

class MakeCar
{
public:
    virtual void MakeHead() = 0;
    virtual void MakeBody() = 0;
    virtual void MakeTail() = 0;

    void Make() // 确定业务逻辑
    {
        MakeTail();
        MakeBody();
        MakeHead();
    }
};

class Jeep: public MakeCar
{
    void MakeHead()
    {
        cout << "jeep head" << endl;
    }

    void MakeBody()
    {
        cout << "jeep body" << endl;
    }

    void MakeTail()
    {
        cout << "jeep tail" << endl;
    }
};

class Bus: public MakeCar
{
    void MakeHead()
    {
        cout << "bus head" << endl;
    }

    void MakeBody()
    {
        cout << "bus body" << endl;
    }

    void MakeTail()
    {
        cout << "bus tail" << endl;
    }
};

int main()
{
    MakeCar* mc = NULL;
    mc = new Jeep();
    mc->Make();
    delete mc;

    return 0;
}
