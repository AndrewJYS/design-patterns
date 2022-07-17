#include <iostream>
#include <string>
#include <list>
using namespace std;

class Visitor;

class ParkElement
{
public:
    string getElement()
    {
        return element;
    }

    virtual void accpet(Visitor* visitor) = 0; //接受访问者访问

protected:
    string element;
};

class Visitor
{
public:
    virtual void visit(ParkElement* parkelement) = 0;
};

class ParkA: public ParkElement
{
public:
    ParkA()
    {
        element = "park element A";
    }

    void accpet(Visitor* v)
    {
        v->visit(this);
    }
};

class ParkB: public ParkElement
{
public:
    ParkB()
    {
        element = "park element B";
    }

    void accpet(Visitor* v)
    {
        v->visit(this);
    }
};

class Park: public ParkElement
{
public:
    Park()
    {
        m_list.clear();
    }

    void setParkElement(ParkElement* pe)
    {
        m_list.push_back(pe);
    }

    void accpet(Visitor* v)
    {
        for (list<ParkElement*>::iterator it = m_list.begin(); it != m_list.end(); it++)
        {
            v->visit(*it);
        }
    }

private:
    list<ParkElement*> m_list;
};

class VisitorA: public Visitor
{
public:
    void visit(ParkElement* parkelement)
    {
        cout << "cleaner A cleans " << parkelement->getElement() << endl;
    }
};

class VisitorB: public Visitor
{
public:
    void visit(ParkElement* parkelement)
    {
        cout << "cleaner B cleans " << parkelement->getElement() << endl;
    }
};

class Manager: public Visitor
{
public:
    void visit(ParkElement* parkelement)
    {
        cout << "manager visits " << parkelement->getElement() << endl;
    }
};

int main()
{
    Visitor* va = new VisitorA;
    Visitor* vb = new VisitorB;
    Visitor* vm = new Manager;
    ParkElement* pa = new ParkA;
    ParkElement* pb = new ParkB;
    Park* park = new Park;

    park->setParkElement(pa);
    park->setParkElement(pb);

    pa->accpet(va);
    pb->accpet(vb);
    park->accpet(vm);

    delete va;
    delete vb;
    delete pa;
    delete pb;

    return 0;
}
