#include<iostream>
#include<vector>
using namespace std;

class Car {
private:
    int carId;
    string carName;

public:
    Car(int id, string name) : carId(id), carName(name) {
    }

    string getCarName() {
        return carName;
    }

    int getCarId() {
        return carId;
    }
};

class Garage {

private:
    vector<Car*> parkedCars;

public:
    void addCarToGarage(Car *c) {
        parkedCars.push_back(c);
    }

    void showAllCars() {
        for (Car* c : parkedCars) {
            cout << c->getCarName() << " , " << c->getCarId() << '\n';
        }
    }
};

int main() {
    Car car1(101, "Ford");
    Car car2(202, "Chevrolet");
    Garage myGarage;
    myGarage.addCarToGarage(&car1);
    myGarage.addCarToGarage(&car2);
    myGarage.showAllCars();

    return 0;
}
