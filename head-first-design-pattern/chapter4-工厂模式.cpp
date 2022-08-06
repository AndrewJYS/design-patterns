#include <iostream>
using namespace std;

class Pizza
{
public:
    void prepare()
    {
        cout << "prepare " << m_name << endl;
    }

    void bake()
    {
        cout << "bake " << m_name << endl;
    }

    void cut()
    {
        cout << "cut " << m_name << endl;
    }

    void box()
    {
        cout << "box " << m_name << endl;
    }

protected:
    string m_name;
};

class NYStyleCheesePizza: public Pizza
{
public:
    NYStyleCheesePizza()
    {
        m_name = "NY Style Cheese Pizza";
    }
};

class NYStyleVeggiePizza: public Pizza
{
public:
    NYStyleVeggiePizza()
    {
        m_name = "NY Style Veggie Pizza";
    }
};

class NYStyleClamPizza: public Pizza
{
public:
    NYStyleClamPizza()
    {
        m_name = "NY Style Clam Pizza";
    }
};

class NYStylePepperoniPizza: public Pizza
{
public:
    NYStylePepperoniPizza()
    {
        m_name = "NY Style Pepperoni Pizza";
    }
};

class ChicagoStyleCheesePizza: public Pizza
{
public:
    ChicagoStyleCheesePizza()
    {
        m_name = "Chicago Style Cheese Pizza";
    }
};

class ChicagoStyleVeggiePizza: public Pizza
{
public:
    ChicagoStyleVeggiePizza()
    {
        m_name = "Chicago Style Veggie Pizza";
    }
};

class ChicagoStyleClamPizza: public Pizza
{
public:
    ChicagoStyleClamPizza()
    {
        m_name = "Chicago Style Clam Pizza";
    }
};

class ChicagoStylePepperoniPizza: public Pizza
{
public:
    ChicagoStylePepperoniPizza()
    {
        m_name = "Chicago Style Pepperoni Pizza";
    }
};

class CaliforniaStyleCheesePizza: public Pizza
{
public:
    CaliforniaStyleCheesePizza()
    {
        m_name = "California Style Cheese Pizza";
    }
};

class CaliforniaStyleVeggiePizza: public Pizza
{
public:
    CaliforniaStyleVeggiePizza()
    {
        m_name = "California Style Veggie Pizza";
    }
};

class CaliforniaStyleClamPizza: public Pizza
{
public:
    CaliforniaStyleClamPizza()
    {
        m_name = "California Style Clam Pizza";
    }
};

class CaliforniaStylePepperoniPizza: public Pizza
{
public:
    CaliforniaStylePepperoniPizza()
    {
        m_name = "California Style Pepperoni Pizza";
    }
};


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

class NYPizzaStore: public PizzaStore
{
public:
    Pizza* createPizza(string type)
    {
        if (type == "cheese")
        {
            return new NYStyleCheesePizza();
        }
        else if (type == "veggie")
        {
            return new NYStyleVeggiePizza();
        }
        else if (type == "clam")
        {
            return new NYStyleClamPizza();
        }
        else if (type == "pepperoni")
        {
            return new NYStylePepperoniPizza();
        }
        else
        {
            return nullptr;
        }
    }
};

class ChicagoPizzaStore: public PizzaStore
{
public:
    Pizza* createPizza(string type)
    {
        if (type == "cheese")
        {
            return new ChicagoStyleCheesePizza();
        }
        else if (type == "veggie")
        {
            return new ChicagoStyleVeggiePizza();
        }
        else if (type == "clam")
        {
            return new ChicagoStyleClamPizza();
        }
        else if (type == "pepperoni")
        {
            return new ChicagoStylePepperoniPizza();
        }
        else
        {
            return nullptr;
        }
    }
};

class CaliforniaPizzaStore: public PizzaStore
{
public:
    Pizza* createPizza(string type)
    {
        if (type == "cheese")
        {
            return new CaliforniaStyleCheesePizza();
        }
        else if (type == "veggie")
        {
            return new CaliforniaStyleVeggiePizza();
        }
        else if (type == "clam")
        {
            return new CaliforniaStyleClamPizza();
        }
        else if (type == "pepperoni")
        {
            return new CaliforniaStylePepperoniPizza();
        }
        else
        {
            return nullptr;
        }
    }
};

void test()
{
    PizzaStore* ps_chicago = new ChicagoPizzaStore();
    ps_chicago->orderPizza("veggie");
    cout << endl;
    /*
    prepare Chicago Style Veggie Pizza
    bake Chicago Style Veggie Pizza
    cut Chicago Style Veggie Pizza
    box Chicago Style Veggie Pizza
    */

    PizzaStore* ps_california = new CaliforniaPizzaStore();
    ps_california->orderPizza("cheese");
    cout << endl;
    /*
    prepare California Style Cheese Pizza
    bake California Style Cheese Pizza
    cut California Style Cheese Pizza
    box California Style Cheese Pizza
    */

    delete ps_chicago;
    delete ps_california;
}

int main()
{
    test();

    return 0;
}
