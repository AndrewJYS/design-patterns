# 设计模式中的重要原则  

## 开放封闭原则  

类的改动是通过增加代码进行的，不是通过修改原来的代码  
运用多态的优势，可以实现开放封闭原则，使代码可扩展  

```c++
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
```

## 依赖倒置原则

依赖于抽象（接口），而不要依赖于具体的实现（类），也就是面向接口编程  

例如：  
有不同厂商的硬盘，内存条和CPU，现在利用这些设备组装电脑
也就是说不同厂商实现不同硬盘，内存条和CPU的接口
而组装电脑时，将接口作为参数

```c++
class Disk
{
public:
    virtual void work() = 0;
};

class Memory
{
public:
    virtual void work() = 0;
};

class CPU
{
public:
    virtual void work() = 0;
};

class IntelCPU: public CPU
{
public:
    void work()
    {
        cout << "Intel CPU" << endl;
    }
};

class XSDisk: public Disk
{
public:
    void work()
    {
        cout << "XS Disk" << endl;
    }
};

class JSDMemory: public Memory
{
public:
    void work()
    {
        cout << "JSD Memory" << endl;
    }
};

class Computer
{
public:
    Computer(Disk* m_disk, Memory* m_memory, CPU* m_cpu)
    {
        this->m_disk = m_disk;
        this->m_memory = m_memory;
        this->m_cpu = m_cpu;
    }

    void work()
    {
        m_disk->work();
        m_memory->work();
        m_cpu->work();
    }

private:
    Disk* m_disk;
    Memory* m_memory;
    CPU* m_cpu;
};
```

## 其他原则  

3.迪米特原则：一个对象应该对其他对象尽可能少的了解，从而减少各个对象间的耦合，提高代码的可维护性
4.接口隔离原则：不应该强迫用户程序依赖他们不需要的接口方法，一个接口应该只提供一种对外功能，不要把所有操作都封装到一个接口中去  
5.里氏替换原则：任何抽象类出现的地方都可以用他的实现类来替换；子类可以扩展父类的功能，但不能改变父类原有的功能  
6.优先使用组合而不是继承原则：如果使用继承，则父类的任何变换都会导致子类功能的变换，如果使用对象组合（类作为成员或成员函数的参数），则会降低这种依赖关系。  
