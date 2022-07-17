#include <iostream>
using namespace std;

class Car {
public:
    Car(string mode) {
        this->mode = mode;
    }

    string mode;
};

class Person {
public:
    void goToWork(Car* c) { // dependency
        cout << "Drive " << c->mode << " to work." << endl;
    }

    Car* fixCar(string mode) { // dependency
        Car* c = new Car(mode);
        cout << "fix car " << mode << endl;
        return c;
    }
};

int main() {
    Car* car = new Car("Volvo");
    Person* person;
    person->goToWork(car);

    Car* fixedCar = person->fixCar("Toyota");
    cout << fixedCar->mode << endl;

    return 0;
}
