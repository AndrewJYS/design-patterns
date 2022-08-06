#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class MenuItem
{
private:
    string name;
    string description;
    bool vegetartian;
    double price;

public:
    MenuItem(string name, string description, bool vegetartian, double price)
    {
        this->name = name;
        this->description = description;
        this->vegetartian = vegetartian;
        this->price = price;
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }

    double getPrice()
    {
        return price;
    }

    bool isVegetarian()
    {
        return vegetartian;
    }

    void print()
    {
        cout << "name: " << name << '\n';
        cout << "description: " << description << '\n';
        if (vegetartian)
        {
            cout << "vegetartian: true\n";
        }
        else
        {
            cout << "vegetartian: false\n";
        }
        cout << "price: " << price << '\n';
    }
};


class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

class DinerMenuIterator final: public Iterator
{
private:
    int position;
    int length;
    MenuItem** items;

public:
    DinerMenuIterator(MenuItem** items, int length)
    {
        this->length = length;
        this->position = 0;
        this->items = new MenuItem*[length];
        for (int i = 0; i < this->length; ++i)
        {
            this->items[i] = items[i];
        }
    }

    MenuItem* next() override
    {
        if (position >= length)
        {
            cout << "error, no next\n";
            return nullptr;
        }

        MenuItem* mi = items[position];
        position++;
        return mi;
    }

    bool hasNext() override
    {
        if (position >= length || items[position] == nullptr)
            return false;
        else
            return true;
    }
};

class PancakeHouseIteraror final: public Iterator
{
private:
    int position;
    list<MenuItem*> items;

public:
    PancakeHouseIteraror(list<MenuItem*> items)
    {
        this->position = 0;
        this->items = items;
    }

    MenuItem* next() override
    {
        if (position >= items.size())
        {
            cout << "error, no next\n";
            return nullptr;
        }

        list<MenuItem*>::iterator it = items.begin();
        for (int i = 0; i < position; ++i)
        {
            it++;
        }

        position++;
        return *it;
    }

    bool hasNext() override
    {
        if (position >= items.size())
            return false;
        return true;
    }
};

class CafeIteraror final: public Iterator
{
private:
    int position;
    unordered_map<string, MenuItem*> items;

public:
    CafeIteraror(unordered_map<string, MenuItem*> items)
    {
        this->position = 0;
        this->items = items;
    }

    MenuItem* next() override
    {
        if (position >= items.size())
        {
            cout << "error, no next\n";
            return nullptr;
        }

        unordered_map<string, MenuItem*>::iterator it = items.begin();
        for (int i = 0; i < position; ++i)
        {
            it++;
        }

        position++;
        return (*it).second;
    }

    bool hasNext() override
    {
        if (position >= items.size())
            return false;
        return true;
    }
};


class Menu
{
public:
    virtual Iterator* createIterator() = 0;
};

class DinerMenu final: public Menu
{
private:

    const int MAX_ITEMS = 6;
    int numberOfItems = 0;
    MenuItem** menuItems;

public:

    DinerMenu()
    {
        menuItems = new MenuItem*[MAX_ITEMS];
        for (int i = 0; i < MAX_ITEMS; ++i)
        {
            menuItems[i] = nullptr;
        }

        addItem("Vegetarian BLT",
                "(Fakin') Bacon with lettuce & tomato on whole wheat",
                true,
                2.99);
        addItem("BLT",
                "Bacon with lettuce & tomato on whole wheat",
                false,
                2.99);
        addItem("Soup of the day",
                "Soup of the day, with a side of potato salad",
                false,
                3.29);
        addItem("Hotdog",
                "A hot dog, with sauerkraut, relish, onions, topped with cheese",
                false,
                3.05);
        // a couple of other Diner Menu items added here
    }

    void addItem(string name, string description, bool vegetarian, double price)
    {
        MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);

        if (numberOfItems >= MAX_ITEMS)
        {
            cout << "Sorry, menu is full! Can't add item to menu\n";
        }
        else
        {
            menuItems[numberOfItems] = menuItem;
            numberOfItems++;
        }
    }

    MenuItem** getMenuItems()
    {
        return menuItems;
    }

    Iterator* createIterator() override
    {
        Iterator* it = new DinerMenuIterator(menuItems, MAX_ITEMS);
        return it;
    }
};

class PancakeHouseMenu final: public Menu
{
private:
    list<MenuItem*> menuItems;

public:
    PancakeHouseMenu()
    {
        menuItems.clear();

        addItem("K&B's Pancake Breakfast",
            "Pancakes with scrambled eggs and toast",
            true,
            2.99);
        addItem("Regular Pancake Breakfast",
            "Pancakes with fried eggs, sausage",
            false,
            2.99);
        addItem("Blueberry Pancakes",
            "Pancakes made with fresh blueberries",
            true,
            3.49);
        addItem("Waffles",
            "Waffles with your choice of blueberries or strawberries",
            true,
            3.59);
    }

    void addItem(string name, string description, bool vegetarian, double price)
    {
        MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
        menuItems.push_back(menuItem);
    }

    list<MenuItem*> getMenuItems()
    {
        return menuItems;
    }

    Iterator* createIterator() override
    {
        Iterator* it = new PancakeHouseIteraror(menuItems);
        return it;
    }
};

class CafeMenu final: public Menu
{
private:
    unordered_map<string, MenuItem*> menuItems;

public:
    CafeMenu()
    {
        menuItems.clear();

        addItem("Veggie Burger and Air Fries",
            "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
            true,
            3.99);
        addItem("Soup of the day",
            "A cup of the soup of the day, with a side salad",
            false,
            3.69);
        addItem("Burrito",
            "A large burrito, with whole pinto beans, salsa, guacamole",
            true,
            4.29);
    }

    void addItem(string name, string description, bool vegetarian, double price)
    {
        MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
        menuItems.insert(make_pair(name, menuItem));
    }

    unordered_map<string, MenuItem*> getMenuItems()
    {
        return menuItems;
    }

    Iterator* createIterator() override
    {
        Iterator* it = new CafeIteraror(menuItems);
        return it;
    }
};

void test()
{
    DinerMenu* dm = new DinerMenu();
    Iterator* itdm = dm->createIterator();

    while (itdm->hasNext())
    {
        MenuItem* m = itdm->next();
        m->print();
    }
    cout << endl;


    PancakeHouseMenu* pm = new PancakeHouseMenu();
    Iterator* itpm = pm->createIterator();

    while (itpm->hasNext())
    {
        MenuItem* m = itpm->next();
        m->print();
    }
    cout << endl;


    CafeMenu* cm = new CafeMenu();
    Iterator* itcm = cm->createIterator();

    while (itcm->hasNext())
    {
        MenuItem* m = itcm->next();
        m->print();
    }
    cout << endl;


    delete itdm;
    delete dm;
    delete itpm;
    delete pm;
    delete itcm;
    delete cm;
}

int main()
{
    test();

    return 0;
}
