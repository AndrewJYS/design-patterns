#include <iostream>
using namespace std;

class absBankStaff
{
public:
    virtual void work() = 0;
};

class Deposit: public absBankStaff
{
public:
    void work()
    {
        cout << "Deposit" << endl;
    }
};

class Withdraw: public absBankStaff
{
    void work()
    {
        cout << "Withdraw" << endl;
    }
};

class Fund: public absBankStaff
{
    void work()
    {
        cout << "Fund" << endl;
    }
};

class advFund: public Fund
{
    void work()
    {
        cout << "advanced fund" << endl;
    }
};

int main()
{
    absBankStaff* bs = NULL;
    bs = new Withdraw();
    bs->work();
    delete bs;

    bs = new advFund();
    bs->work();
    delete bs;

    return 0;
}
