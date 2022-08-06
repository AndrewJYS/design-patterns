#include <iostream>
#include <string>
using namespace std;

class House
{ //House对象的表示
public:
    void setDoor(string door)
    {
        this->m_door = door;
    }
    void setWall(string wall)
    {
        this->m_wall = wall;
    }
    void setWindow(string window)
    {
        this->m_window = window;
    }

    string getDoor()
    {
        cout << m_door << endl;
        return m_door;
    }
    string getWall()
    {
        cout << m_wall << endl;
        return m_wall;
    }
    string getWindow()
    {
        cout << m_window << endl;
        return m_window;
    }
private:
    string m_door;
    string m_wall;
    string m_window;
};

class Builder
{ // House对象的构建过程
public:
    virtual void buildWall() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindow() = 0;
    virtual House* getHouse() = 0;
};

class FlatBuilder: public Builder
{ // 公寓的建造者
public:
    FlatBuilder()
    {
        m_house = new House;
    }
    void buildWall()
    {
        m_house->setWall("flat wall");
    }
    void buildDoor()
    {
        m_house->setDoor("flat door");
    }
    void buildWindow()
    {
        m_house->setWindow("flat window");
    }
    House* getHouse()
    {
        return m_house;
    }
private:
    House* m_house;
};

class VillaBuilder: public Builder
{ // 别墅的建造者
public:
    VillaBuilder()
    {
        m_house = new House;
    }
    void buildWall()
    {
        m_house->setWall("Villa wall");
    }
    void buildDoor()
    {
        m_house->setDoor("Villa door");
    }
    void buildWindow()
    {
        m_house->setWindow("Villa window");
    }
    House* getHouse()
    {
        return m_house;
    }
private:
    House* m_house;
};

class Director
{ //设计师指挥建造者建造
public:
    Director(Builder* build)
    {
        this->m_build = build;
    }
    void Construct()
    {
        m_build->buildWall();
        m_build->buildDoor();
        m_build->buildWindow();
    }
private:
    Builder* m_build;
};

int main()
{
    House* house = NULL;
    Builder* builder = NULL;
    Director* director = NULL;

    builder = new VillaBuilder();
    director = new Director(builder);
    director->Construct();
    house = builder->getHouse();
    house->getDoor();
    house->getWall();
    house->getWindow();

    delete house;
    delete builder;

    builder = new FlatBuilder();
    director = new Director(builder);
    director->Construct();
    house = builder->getHouse();
    house->getDoor();
    house->getWall();
    house->getWindow();

    delete house;
    delete builder;
    delete director;

    return 0;
}
