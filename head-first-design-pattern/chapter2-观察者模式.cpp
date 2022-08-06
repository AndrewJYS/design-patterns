#include <iostream>
#include <list>
using namespace std;

class Observer
{
public:
    virtual void update(double, double, double) = 0;
};

class Subject
{
public:
    virtual void registerObserver(Observer* ob) = 0;
    virtual void removeObserver(Observer* ob) = 0;
    virtual void notifyObservers() = 0;
};

class DisplayElement
{
public:
    virtual void display() = 0;
};

class WeatherData: public Subject
{
public:
    WeatherData()
    {
        observers.clear();
    }

    void registerObserver(Observer* ob)
    {
        observers.push_back(ob);
    }

    void removeObserver(Observer* ob)
    {
        observers.remove(ob);
    }

    void notifyObservers()
    {
        for (auto ob: observers) // ob is a pointer
        {
            ob->update(m_temperature, m_humidity, m_pressure);
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(double temperature, double humidity, double pressure)
    {
        this->m_temperature = temperature;
        this->m_humidity = humidity;
        this->m_pressure = pressure;
        measurementsChanged();
    }

private:
    list<Observer*> observers;
    double m_temperature;
    double m_humidity;
    double m_pressure;
};

class CurrentConditionsDisplay: public Observer, DisplayElement
{
public:
    CurrentConditionsDisplay(WeatherData* wd)
    {
        this->m_weatherData = *wd;
        wd->registerObserver(this);
    }

    void update(double temperature, double humidity, double pressure)
    {
        this->m_temperature = temperature;
        this->m_humidity = humidity;
        this->m_pressure = pressure;
        display();
    }

    void display()
    {
        cout << "Current conditions: " << m_temperature << "C degrees, " << m_humidity <<
            "% humidity, and " << m_pressure << "hpa" << endl;
    }

private:
    double m_temperature;
    double m_humidity;
    double m_pressure;
    WeatherData m_weatherData;
};

void test()
{
    WeatherData* weatherData = new WeatherData();
    CurrentConditionsDisplay* ccd1 = new CurrentConditionsDisplay(weatherData);

    weatherData->setMeasurements(20.4, 79, 1002);
    weatherData->setMeasurements(21.2, 86, 1001);
    weatherData->setMeasurements(21.4, 88, 999);

    /*
    Current conditions: 20.4C degrees, 79% humidity, and 1002hpa
    Current conditions: 21.2C degrees, 86% humidity, and 1001hpa
    Current conditions: 21.4C degrees, 88% humidity, and 999hpa
    */

    delete weatherData;
    delete ccd1;
}

int main()
{
    test();

    return 0;
}
