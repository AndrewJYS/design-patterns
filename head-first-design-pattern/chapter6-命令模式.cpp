#include <iostream>
#include <vector>
using namespace std;

//设备类
class Light
{
public:
    Light() {}
    void on() { cout << "light is on" << endl; }
    void off() { cout << "light is off" << endl; }
};

class GarageDoor
{
public:
    GarageDoor() {}
    void open() { cout << "garage door is open" << endl; }
    void close() { cout << "garage door is close" << endl; }
};

class CeilingFan
{
public:
    CeilingFan() { speed = OFF; }

    void high()
    {
        speed = HIGH;
        cout << "the ceiling fan speed is high" << endl;
    }

    void medium()
    {
        speed = MEDIUM;
        cout << "the ceiling fan speed is medium" << endl;
    }

    void low()
    {
        speed = LOW;
        cout << "the ceiling fan speed is low" << endl;
    }

    void off()
    {
        speed = OFF;
        cout << "the ceiling fan is off" << endl;
    }

    int getSpeed()
    {
        return speed;
    }

    const int HIGH = 3;
    const int MEDIUM = 2;
    const int LOW = 1;
    const int OFF = 0;

private:
    int speed;
};


//命令类
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class LightOnCommand: public Command
{
public:
    LightOnCommand(Light* light) { this->m_light = light; }
    void execute() { m_light->on(); }
    void undo() { m_light->off(); }

private:
    Light* m_light;
};

class LightOffCommand: public Command
{
public:
    LightOffCommand(Light* light) { this->m_light = light; }
    void execute() { m_light->off(); }
    void undo() { m_light->on(); }

private:
    Light* m_light;
};

class GarageDoorOpenCommand: public Command
{
public:
    GarageDoorOpenCommand(GarageDoor* g) { this->m_garageDoor = g; }
    void execute() { m_garageDoor->open(); }
    void undo() { m_garageDoor->close(); }

private:
    GarageDoor* m_garageDoor;
};

class GarageDoorCloseCommand: public Command
{
public:
    GarageDoorCloseCommand(GarageDoor* g) { this->m_garageDoor = g; }
    void execute() { m_garageDoor->close(); }
    void undo() { m_garageDoor->open(); }

private:
    GarageDoor* m_garageDoor;
};

class CeilingFanHighCommand: public Command
{
public:
    CeilingFanHighCommand(CeilingFan* c)
    {
        m_ceilingFan = c;
    }

    void execute()
    {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->high();
    }

    void undo()
    {
        if (m_prevSpeed == m_ceilingFan->HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == m_ceilingFan->MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == m_ceilingFan->LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == m_ceilingFan->OFF) {
            m_ceilingFan->off();
        }
    }

private:
    CeilingFan* m_ceilingFan;
    int m_prevSpeed;
};

class CeilingFanMediumCommand: public Command
{
public:
    CeilingFanMediumCommand(CeilingFan* c)
    {
        m_ceilingFan = c;
    }

    void execute()
    {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->medium();
    }

    void undo()
    {
        if (m_prevSpeed == m_ceilingFan->HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == m_ceilingFan->MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == m_ceilingFan->LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == m_ceilingFan->OFF) {
            m_ceilingFan->off();
        }
    }

private:
    CeilingFan* m_ceilingFan;
    int m_prevSpeed;
};

class CeilingFanOffCommand: public Command
{
public:
    CeilingFanOffCommand(CeilingFan* c)
    {
        m_ceilingFan = c;
    }

    void execute()
    {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->off();
    }

    void undo()
    {
        if (m_prevSpeed == m_ceilingFan->HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == m_ceilingFan->MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == m_ceilingFan->LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == m_ceilingFan->OFF) {
            m_ceilingFan->off();
        }
    }

private:
    CeilingFan* m_ceilingFan;
    int m_prevSpeed;
};


//命令的提交者类（这里是遥控器）
class RemoteControl
{
public:
    RemoteControl()
    {
        m_onCommands.resize(m_numSlots);
        m_offCommands.resize(m_numSlots);

        Command* noCommand = nullptr;
        for (int i = 0; i < m_numSlots; ++i)
        {
            m_onCommands[i] = noCommand;
            m_offCommands[i] = noCommand;
        }
        m_prevCommand = noCommand;
    }

    void setCommand(int slot, Command* onCommand, Command* offCommand)
    {
        m_onCommands[slot] = onCommand;
        m_offCommands[slot] = offCommand;
    }

    void onButtonWasPressed(int slot)
    {
        if (m_onCommands[slot])
        {
            m_onCommands[slot]->execute();
        }
        m_prevCommand = m_onCommands[slot];
    }

    void offButtonWasPressed(int slot)
    {
        if (m_offCommands[slot])
        {
            m_offCommands[slot]->execute();
        }
        m_prevCommand = m_offCommands[slot];
    }

    void undoButtonWasPressed()
    {
        m_prevCommand->undo();
    }

private:
    vector<Command*> m_onCommands;
    vector<Command*> m_offCommands;
    const int m_numSlots = 7;
    Command* m_prevCommand;
};

void test()
{
    RemoteControl* re = new RemoteControl();

    CeilingFan* cf = new CeilingFan();
    CeilingFanHighCommand* cfhc = new CeilingFanHighCommand(cf);
    CeilingFanMediumCommand* cfmc = new CeilingFanMediumCommand(cf);
    CeilingFanOffCommand* cfoc = new CeilingFanOffCommand(cf);

    Light* light = new Light();
    LightOnCommand* lon = new LightOnCommand(light);
    LightOffCommand* loff = new LightOffCommand(light);

    re->setCommand(0, cfhc, cfoc);
    re->setCommand(1, cfmc, cfoc);
    re->setCommand(2, lon, loff);

    re->onButtonWasPressed(0);
    re->offButtonWasPressed(0);
    re->onButtonWasPressed(0);
    re->offButtonWasPressed(1);
    re->onButtonWasPressed(2);
    re->offButtonWasPressed(2);

    re->undoButtonWasPressed();
}

int main()
{
    test();

    return 0;
}
