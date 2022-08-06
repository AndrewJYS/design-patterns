#include <iostream>
using namespace std;

class Memento
{
public:
    Memento(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string getName()
    {
        return m_name;
    }

    int getAge()
    {
        return m_age;
    }

    void setName(string name)
    {
        this->m_name = name;
    }

    void setAge(int age)
    {
        this->m_age = age;
    }

private:
    string m_name;
    int m_age;
};

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string getName()
    {
        return m_name;
    }

    int getAge()
    {
        return m_age;
    }

    void setName(string name)
    {
        this->m_name = name;
    }

    void setAge(int age)
    {
        this->m_age = age;
    }

    Memento* createMemento()
    {
        return new Memento(m_name, m_age);
    }

    void setMemento(Memento* memento)
    {
        this->m_name = memento->getName();
        this->m_age = memento->getAge();
    }

    void printInfo()
    {
        cout << "name: " << m_name << "; age: " << m_age << endl;
    }

private:
    string m_name;
    int m_age;
};

class CareTaker
{
public:
    CareTaker(Memento* memento)
    {
        this->m_memento = memento;
    }
    Memento* getMemento()
    {
        return m_memento;
    }
    void setMemento(Memento* memento)
    {
        this->m_memento = memento;
    }
private:
    Memento* m_memento;
};

int main()
{
    Memento* me = NULL;
    Person* p = NULL;
    CareTaker* caretaker = NULL;

    p = new Person("Mike", 15);
    p->printInfo();

    caretaker = new CareTaker(p->createMemento());
    p->setAge(20);
    p->setName("Jack");
    p->printInfo();

    p->setMemento(caretaker->getMemento());
    p->printInfo();

    delete p;
    delete me;
    delete caretaker;

    return 0;
}
