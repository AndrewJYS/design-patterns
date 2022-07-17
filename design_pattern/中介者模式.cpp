#include <iostream>
using namespace std;

class Mediator;
class Person;

class Person
{
public:
    Person(string name, int sex, int cond, Mediator* mediator)
    {
        m_name = name;
        m_sex= sex;
        m_cond = cond;
        m_mediator = mediator;
    }

    string getName()
    {
        return m_name;
    }

    int getSex()
    {
        return m_sex;
    }

    int getCond()
    {
        return m_cond;
    }

    virtual void getPartner(Person* p) = 0;

protected:
    string m_name;
    int m_sex;
    int m_cond;
    Mediator* m_mediator;
};

class Mediator
{
public:
    void setMan(Person* man)
    {
        pMan = man;
    }

    void setWoman(Person* woman)
    {
        pWoman = woman;
    }

    void getPartner()
    {
        if (pMan->getSex() == pWoman->getSex())
        {
            cout << "the same sex" << endl;
            return;
        }
        if (pMan->getCond() == pWoman->getCond())
        {
            cout << pMan->getName() << " and " << pWoman->getName() << ": conditions match" << endl;
        }
        else
        {
            cout << pMan->getName() << " and " << pWoman->getName() << ": conditions do not match" << endl;
        }
    }

private:
    Person* pMan;
    Person* pWoman;
};

class Woman: public Person
{
public:
    Woman(string name, int sex, int cond, Mediator* mediator): Person(name, sex, cond, mediator)
    {

    }

    void getPartner(Person* p)
    {
        m_mediator->setMan(p);
        m_mediator->setWoman(this);
        m_mediator->getPartner(); // 找对象
    }
};

class Man: public Person
{
public:
    Man(string name, int sex, int cond, Mediator* mediator): Person(name, sex, cond, mediator)
    {

    }

    void getPartner(Person* p)
    {
        m_mediator->setMan(this);
        m_mediator->setWoman(p);
        m_mediator->getPartner(); // 找对象
    }
};

int main()
{
    Person* w1 = NULL;
    Person* w2 = NULL;
    Person* m1 = NULL;
    Person* m2 = NULL;
    Mediator* mediator = new Mediator();

    w1 = new Woman("Alice", 2, 5, mediator);
    w2 = new Woman("Elizabeth", 2, 4, mediator);
    m1 = new Man("Bob", 1, 5, mediator);
    m2 = new Man("Mike", 1, 4, mediator);

    w1->getPartner(m1);
    w1->getPartner(w1);
    w1->getPartner(m2);

    return 0;
}
