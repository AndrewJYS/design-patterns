#include <iostream>
using namespace std;

class CarHandle //造完车需要把任务传递下去
{
public:
    virtual void HandleCar() = 0;

    CarHandle* setNextHandle(CarHandle* handle)
    {
        m_handle = handle;
        return m_handle;
    }

protected:
    CarHandle* m_handle;
};

class HeadCarHandle: public CarHandle
{
public:
    virtual void HandleCar()
    {
        cout << "handel car head" << endl;
        if (m_handle != NULL)
        { //造完车头后把任务递交给下一个处理者
            m_handle->HandleCar();
        }
    }
};

class BodyCarHandle: public CarHandle
{
public:
    virtual void HandleCar()
    {
        cout << "handel car body" << endl;
        if (m_handle != NULL)
        { //造完车身后把任务递交给下一个处理者
            m_handle->HandleCar();
        }
    }
};

class TailCarHandle: public CarHandle
{
public:
    virtual void HandleCar()
    {
        cout << "handel car tail" << endl;
        if (m_handle != NULL)
        { //造完车尾后把任务递交给下一个处理者
            m_handle->HandleCar();
        }
    }
};

void run()
{
    CarHandle* head = new HeadCarHandle();
    CarHandle* body = new BodyCarHandle();
    CarHandle* tail = new TailCarHandle();

    // 下面这种写法会将客户端逻辑写死，但如果造车的逻辑改变，客户端也要修改代码，扩展性不高
    // 应该使用责任链模式
    head->HandleCar();
    body->HandleCar();
    tail->HandleCar();

    delete head;
    delete body;
    delete tail;
}

int main()
{
    CarHandle* head = new HeadCarHandle();
    CarHandle* body = new BodyCarHandle();
    CarHandle* tail = new TailCarHandle();

    head->setNextHandle(body);
    body->setNextHandle(tail);
    tail->setNextHandle(NULL);

    head->HandleCar();

    delete head;
    delete body;
    delete tail;

    return 0;
}
