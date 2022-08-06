#include <iostream>
using namespace std;

#define SIZE 10
typedef int Object;

class Aggregate;

class MyIterator
{
public:
    MyIterator(Aggregate* ag)
    {
        m_ag = ag;
        m_current_index = 0;
    }

    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool isDone() = 0;
    virtual Object currentItem() = 0;

protected:
    int m_current_index;
    Aggregate* m_ag;
};

class Aggregate
{
public:
    virtual MyIterator* createIterator() = 0;
    virtual Object getItem(int index) = 0;
    virtual int getSize() = 0;
};

class ConcreteIterator: public MyIterator
{
public:
    ConcreteIterator(Aggregate* ag): MyIterator(ag)
    {
        m_ag = ag;
        m_current_index = 0;
    }

    void First()
    {
        m_current_index = 0; // 当前游标回到位置0
    }

    void Next()
    {
        if (m_current_index < m_ag->getSize())
            m_current_index++;
    }

    bool isDone()
    {
        return m_current_index == m_ag->getSize();
    }

    Object currentItem()
    {
        return m_ag->getItem(m_current_index);
    }
};

class ConcreteAggregate: public Aggregate
{
public:
    ConcreteAggregate()
    {
        for (int i = 0; i < SIZE; i++)
        {
            object[i] = i + 100;
        }
    }

    MyIterator* createIterator()
    {
        return new ConcreteIterator(this);
    }

    Object getItem(int index)
    {
        return object[index];
    }

    int getSize()
    {
        return SIZE;
    }

private:
    Object object[SIZE];
};

int main()
{
    Aggregate* ag = new ConcreteAggregate();
    MyIterator* it = ag->createIterator();

    for (; !(it->isDone()); it->Next())
    {
        cout << it->currentItem() << " ";
    } // 100 101 102 103 104 105 106 107 108 109

    return 0;
}
