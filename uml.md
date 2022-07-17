# UML 类之间的关系  

## 依赖关系（虚线）  

在C++中，可以在将类A作为类B的参数，或者将类A作为类B成员函数的返回值，称为类B依赖于类A  

```c++
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

    return 0;
}
```

## 关联（实线）  

类A是类B的成员对象，称为类B关联（到）类A，比如Person有一辆车，就称作车类关联到Person类  
与关联类似的还有两种关系，分别是聚合和组合。  
聚合（空心菱形加实线）：表示整体和部分的关系，比如车和轮胎，车和发动机  
组合（实心菱形加实线）：表示整体和部分的关系，但更强调整体和部分是相互依存的，如果整体或部分消失，则另一半也会消失  

```c++
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
```
