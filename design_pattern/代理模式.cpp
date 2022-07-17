#include <iostream>
using namespace std;

class Bookshop
{
public:
    virtual void sellbook() = 0;
};

class RealBookshop: public Bookshop
{
public:
    void sellbook()
    {
        cout << "sell books" << endl;
    }
};

class DangdangProxy: public Bookshop
{
public:
    void sellbook()
    {
        RealBookshop* rbs = new RealBookshop();
        discount();
        rbs->sellbook();
        discount();
    }

    void discount()
    {
        cout << "discount" << endl;
    }
};

int main()
{
    Bookshop* bs = new DangdangProxy();
    bs->sellbook();
    return 0;
}
