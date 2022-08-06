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
    Person(string mode) {
        c = new Car(mode);
    }

    void goToWork() {
        cout << "Drive " << c->mode << " to work." << endl;
    }

    Car* fixCar() {
        cout << "fix car " << c->mode << endl;
        return c;
    }

private:
    Car* c; // association
};

int main() {
    Person* person = new Person("Volvo");
    person->goToWork();

    Car* fixedCar = person->fixCar();
    cout << fixedCar->mode << endl;

    return 0;
}
