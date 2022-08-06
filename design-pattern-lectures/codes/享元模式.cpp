#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    virtual void printT() = 0;

protected:
    string m_name;
    int m_age;
};

class Teacher: public Person
{
public:
    Teacher(string name, int age, string id): Person(name, age)
    {
        this->m_id = id;
    }

    void printT()
    {
        cout << "name: " << m_name << "; age: " << m_age << "; id: " << m_id << endl;
    }

private:
    string m_id;
};

class FlyWeightTeacherFactory
{
public:
    FlyWeightTeacherFactory()
    {
        map1.clear();
    }

    ~FlyWeightTeacherFactory()
    {
        while (!map1.empty())
        {
            Person* tmp = NULL;
            unordered_map<string, Person* >::iterator it = map1.begin();
            tmp = it->second;
            map1.erase(it); // 把节点移出map
            delete tmp;
        }
    }

    Person* getTeacher(string id)
    {
        string tmpname;
        int tmpage;
        unordered_map<string, Person* >::iterator it;
        it = map1.find(id);
        if (it == map1.end()) // 没有找到
        {
            cout << "Please enter name and age: " << endl;
            cin >> tmpname;
            cin >> tmpage;
            Teacher* tmp = new Teacher(tmpname, tmpage, id);
            map1.insert(pair<string, Person* >(id, tmp));
            return tmp;
        }
        else
        {
            return it->second;
        }
        return NULL;
    }

private:
    unordered_map<string, Person* > map1;
};

int main()
{
    Person* p1 = NULL;
    Person* p2 = NULL;

    FlyWeightTeacherFactory* fwtf = new FlyWeightTeacherFactory();
    p1 = fwtf->getTeacher("001");
    p1->printT();

    p2 = fwtf->getTeacher("001");
    p2->printT();

    delete fwtf;

    return 0;
}
