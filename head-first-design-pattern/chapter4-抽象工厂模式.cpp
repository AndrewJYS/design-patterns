#include <iostream>
#include <list>
#include <string>
using namespace std;

// 原料类
class Dough{};
class ThinCrustDough: public Dough{};
class ThickCrustDough: public Dough{};

class Sauce{};
class MarinaraSauce: public Sauce{};
class PlumTomatoSauce: public Sauce{};

class Cheese{};
class ReggianoCheese: public Cheese{};
class MozzarellaCheese: public Cheese{};

class Veggie{};
class Garlic: public Veggie{};
class Onion: public Veggie{};
class Mushroom: public Veggie{};
class RedPepper: public Veggie{};
class BlackOlives: public Veggie{};
class Spinach: public Veggie{};
class Eggplant: public Veggie{};

class Pepperoni{};
class SlicedPepperoni: public Pepperoni{};

class Clams{};
class FreshClams: public Clams{};
class FrozenClams: public Clams{};


// Pizza抽象类
class Pizza
{
public:
    virtual void prepare() = 0;

    void bake()
    {
        cout << "bake for 25 minutes at 350" << endl;
    }

    void cut()
    {
        cout << "cutting the pizza into diagonal slices" << endl;
    }

    void box()
    {
        cout << "place pizza in official PizzaStore box" << endl;
    }

    void setName(string name)
    {
        this->m_name = name;
    }

    string getName()
    {
        return m_name;
    }

protected:
    string m_name;
    Dough* m_dough;
    Sauce* m_sauce;
    list<Veggie*> m_veggies;
    Cheese* m_cheese;
    Pepperoni* m_pepperoni;
    Clams* m_clams;
};

//抽象工厂类
class PizzaIngredientFactory
{
public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    virtual list<Veggie*> createVeggies() = 0;
    virtual Pepperoni* createPepperoni() = 0;
    virtual Clams* createClams() = 0;
};

//实现纽约原料工厂
class NYPizzaIngredientFactory: public PizzaIngredientFactory
{
public:
    Dough* createDough()
    {
        return new ThinCrustDough();
    }

    Sauce* createSauce()
    {
        return new MarinaraSauce();
    }

    Cheese* createCheese()
    {
        return new ReggianoCheese();
    }

    list<Veggie*> createVeggies()
    {
        list<Veggie*> tmp {new Garlic(), new Onion(), new Mushroom(), new RedPepper()};
        return tmp;
    }

    Pepperoni* createPepperoni()
    {
        return new SlicedPepperoni();
    }

    Clams* createClams()
    {
        return new FreshClams();
    }
};

//实现芝加哥原料工厂
class ChicagoPizzaIngredientFactory: public PizzaIngredientFactory
{
public:
    Dough* createDough()
    {
        return new ThickCrustDough();
    }

    Sauce* createSauce()
    {
        return new PlumTomatoSauce();
    }

    Cheese* createCheese()
    {
        return new MozzarellaCheese();
    }

    list<Veggie*> createVeggies()
    {
        list<Veggie*> tmp {new BlackOlives(), new Spinach(), new Eggplant()};
        return tmp;
    }

    Pepperoni* createPepperoni()
    {
        return new SlicedPepperoni();
    }

    Clams* createClams()
    {
        return new FrozenClams();
    }
};

// 实现CheesePizza类
class CheesePizza: public Pizza
{
public:
    CheesePizza(PizzaIngredientFactory* pif)
    {
        m_ingredientFactory = pif;
    }

    void prepare()
    {
        cout << "preparing " << m_name << endl;
        m_dough = m_ingredientFactory->createDough();
        m_sauce = m_ingredientFactory->createSauce();
        m_cheese = m_ingredientFactory->createCheese();
    }

private:
    PizzaIngredientFactory* m_ingredientFactory;
};

// 实现ClamPizza类
class ClamPizza: public Pizza
{
public:
    ClamPizza(PizzaIngredientFactory* pif)
    {
        m_ingredientFactory = pif;
    }

    void prepare()
    {
        cout << "preparing " << m_name << endl;
        m_dough = m_ingredientFactory->createDough();
        m_sauce = m_ingredientFactory->createSauce();
        m_cheese = m_ingredientFactory->createCheese();
        m_clams = m_ingredientFactory->createClams();
    }

private:
    PizzaIngredientFactory* m_ingredientFactory;
};

// Pizza店抽象类
class PizzaStore
{
public:
    Pizza* orderPizza(string type)
    {
        Pizza* pizza;
        pizza = createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual Pizza* createPizza(string type) = 0;
};

// 实现具体的NYPizzaStore
class NYPizzaStore: public PizzaStore
{
public:
    Pizza* createPizza(string type)
    {
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();

        if (type == "cheese")
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York style Cheese Pizza");
        }
        else if (type == "clam")
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("New York style Clam Pizza");
        }

        return pizza;
    }
};

// 实现具体的ChicagoPizzaStore
class ChicagoPizzaStore: public PizzaStore
{
public:
    Pizza* createPizza(string type)
    {
        Pizza* pizza = nullptr;
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();

        if (type == "cheese")
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago style Cheese Pizza");
        }
        else if (type == "clam")
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("Chicago style Clam Pizza");
        }

        return pizza;
    }
};

void test()
{
    PizzaStore* ps_ny = new NYPizzaStore();
    ps_ny->orderPizza("cheese");
    cout << endl;
    /*
    preparing New York style Cheese Pizza
    bake for 25 minutes at 350
    cutting the pizza into diagonal slices
    place pizza in official PizzaStore box
    */

    PizzaStore* ps_ch = new ChicagoPizzaStore();
    ps_ch->orderPizza("clam");
    cout << endl;
    /*
    preparing Chicago style Clam Pizza
    bake for 25 minuztes at 350
    cutting the pizza into diagonal slices
    place pizza in official PizzaStore box
    */

    delete ps_ch;
    delete ps_ny;
}


int main()
{
    test();

    return 0;
}
