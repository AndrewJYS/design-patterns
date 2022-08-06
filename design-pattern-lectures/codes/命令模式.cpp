#include <iostream>
#include "list"
using namespace std;

class Doctor
{
public:
    void treat_eye()
    {
        cout << "treat eyes" << endl;
    }

    void treat_nose()
    {
        cout << "treat noses" << endl;
    }
};

class Command
{
public:
    virtual void treat() = 0;
};

class CommandTreatEye: public Command
{
public:
    CommandTreatEye(Doctor* doctor)
    {
        m_doctor = doctor; //注入
    }

    void treat()
    {
        m_doctor->treat_eye();
    }

private:
    Doctor* m_doctor;
};

class CommandTreatNose: public Command
{
public:
    CommandTreatNose(Doctor* doctor)
    {
        m_doctor = doctor; //注入
    }

    void treat()
    {
        m_doctor->treat_nose();
    }

private:
    Doctor* m_doctor;
};

class Nurse
{
public:
    Nurse(Command* command) // 注入，客户端可以面向命令编程
    {
        this->m_command = command;
    }

    void commit() // 提交命令
    {
        m_command->treat();
    }
private:
    Command* m_command;
};

class HeadNurse
{
public:
    HeadNurse()
    {
        m_list.clear();
    }
    void setCommand(Command* command)
    {
        m_list.push_back(command);
    }

    void commit() // 提交命令
    {
        for (list<Command*>::iterator it = m_list.begin(); it != m_list.end(); it++)
        {
            (*it)->treat();
        }
    }
private:
    Command* m_command;
    list<Command* > m_list;
};

int main()
{
    // 医生直接看病
    Doctor* doctor = NULL;
    doctor = new Doctor;
    doctor->treat_eye();
    delete doctor;
    cout << endl;

    // 医生通过护士提交的命令治疗
    Nurse* nurse = NULL;
    Command* com = NULL;

    doctor = new Doctor;
    //com = new CommandTreatEye(doctor);
    com = new CommandTreatNose(doctor);
    nurse = new Nurse(com);

    nurse->commit();
    delete doctor;
    delete com;
    delete nurse;
    cout << endl;

    // 通过HeadNurse批量下达命令
    HeadNurse* headnurse = NULL;
    Command* com1 = NULL;
    Command* com2 = NULL;
    Command* com3 = NULL;
    doctor = new Doctor();
    com1 = new CommandTreatEye(doctor);
    com2 = new CommandTreatNose(doctor);
    com3 = new CommandTreatEye(doctor);
    headnurse = new HeadNurse();
    headnurse->setCommand(com1);
    headnurse->setCommand(com2);
    headnurse->setCommand(com3);
    headnurse->commit();

    delete doctor;
    delete com;
    delete nurse;
    delete headnurse;

    return 0;
}
