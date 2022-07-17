#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Person
{
public:
    virtual Person* clone() = 0;
    virtual void printPerson() = 0;
};

class CPlusPlusProgrammer: public Person
{
public:
    CPlusPlusProgrammer()
    {
        m_name = "";
        m_age = 0;
        m_description = NULL;
    }

    CPlusPlusProgrammer(string name, int age, char* p)
    {
        this->m_name = name;
        this->m_age = age;
        m_description = new char[strlen(p) + 1];
        strcpy(this->m_description, p);
    }

    void setDescription(char* p)
    {
        if (m_description != NULL)
            delete m_description;

        m_description = new char[strlen(p) + 1];
        strcpy(m_description, p);
    }

    void printPerson()
    {
        cout << "name: " << m_name << "; age: " << m_age << "; description: " << m_description << endl;
    }

    Person* clone()
    {
        CPlusPlusProgrammer* p = new CPlusPlusProgrammer();
        // *p = *this; // 默认是浅拷贝
        p->m_age = this->m_age;
        p->m_name = this->m_name;
        p->m_description = new char[strlen(m_description) + 1];
        strcpy(p->m_description, this->m_description);

        return p;
    }

private:
    string m_name;
    int m_age;
    char* m_description;
};

int main()
{
    Person* c1 = new CPlusPlusProgrammer("mike", 30, "aaaa");
    c1->printPerson();

    Person* c2 = c1->clone();
    c2->printPerson();

    return 0;
}
