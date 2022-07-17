#include <iostream>
using namespace std;

class subSystemA
{
public:
    void run()
    {
        cout << "subsystem A runs" << endl;
    }
};
class subSystemB
{
public:
    void run()
    {
        cout << "subsystem B runs" << endl;
    }
};
class subSystemC
{
public:
    void run()
    {
        cout << "subsystem C runs" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        sysA = new subSystemA;
        sysB = new subSystemB;
        sysC = new subSystemC;
    }

    void run()
    {
        sysA->run();
        sysB->run();
        sysC->run();
    }

    ~Facade()
    {
        delete sysA;
        delete sysB;
        delete sysC;
    }
private:
    subSystemA* sysA;
    subSystemB* sysB;
    subSystemC* sysC;
};

int main()
{
    Facade* f = new Facade();
    f->run();
    delete f;

    return 0;
}
