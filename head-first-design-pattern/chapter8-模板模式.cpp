#include <iostream>

class CaffeineBeverage
{
public:
    virtual void prepareRecipe() final //final用来修饰类的虚函数不能被重写
    {
        boilwater();
        brew();
        pourInCup();

        if (customerWantsCondiments())
        {
            addCondiment();
        }
    }

protected:
    virtual void brew() = 0;
    virtual void addCondiment() = 0;

    virtual void boilwater() final
    {
        std::cout << "Boiling water\n";
    }

    virtual void pourInCup() final
    {
        std::cout << "Pouring into cup\n";
    }

    virtual bool customerWantsCondiments()
    {
        return true;
    }
};

class Tea final: public CaffeineBeverage //final 用来修饰类，不能被继承
{
private:
    void brew() override //override仅能修饰虚函数，表明重写了父类函数
    {
        std::cout << "Steeping the tea\n";
    }

    void addCondiment() override
    {
        std::cout << "Adding Lemon\n";
    }
};

class Coffee final: public CaffeineBeverage
{
public:
    void brew() override
    {
        std::cout << "Dripping coffee through filter\n";
    }

    void addCondiment() override
    {
        std::cout << "Adding sugar and milk\n";
    }

    bool customerWantsCondiments() override
    {
        std::string ans = getUserInput();
        if (ans == "y")
            return true;
        return false;
    }

    std::string getUserInput()
    {
        std::string ans;

        std::cout << "would you like milk and sugar with your coffee (y/n)?\n";
        std::cin >> ans;
        return ans;
    }

};

void test()
{
    Coffee* coffee = new Coffee();
    coffee->prepareRecipe();
}

int main()
{
    test();

    return 0;
}
