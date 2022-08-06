#include <iostream>
using namespace std;

// 有不同厂商的硬盘，内存条和CPU，现在利用这些设备组装电脑
// 也就是说不同厂商实现不同硬盘，内存条和CPU的接口
// 而组装电脑时，将接口作为参数

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

int main()
{
    Disk* disk = new XSDisk();
    Memory* memory = new JSDMemory();
    CPU* cpu = new IntelCPU();
    Computer* com = new Computer(disk, memory, cpu);
    com->work();

    delete disk;
    delete memory;
    delete cpu;
    delete com;
    return 0;
}
