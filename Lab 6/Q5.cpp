#include <iostream>

using namespace std;

class Vehicles {
    protected:
        double price;
    
    public:
        Vehicles(double p) : price(p) {}

};

class Car : public Vehicles {
    protected:
        int seatingCapacity;
        int numberOfDoors;
        string fuelType;

    public:
        Car(int s, int n, string f, double p) : Vehicles(p), seatingCapacity(s), numberOfDoors(n), fuelType(f) {}

};

class Audi : public Car {
    private:
        string model;

    public:
        Audi(int s, int n, string f, double p, string m) : Car(s, n, f, p), model(m) {}

        void displayDetails() {
            cout << "Audi Model: " << model << ", Seats: " << seatingCapacity << ", Doors: " << numberOfDoors << ", Fuel Type: " << fuelType << ", Price: " << price << endl;
        }

};

class Motorcycle : public Vehicles {
    protected:  
        int cylinders;
        int gears;
        int wheels;

    public:
        Motorcycle(int c, int g, int w, double p) : Vehicles(p), cylinders(c), gears(g), wheels(w) {}

};

class Yamaha : public Motorcycle {
    private:
        string make;

    public:
        Yamaha(int c, int g, int w, double p, string m) : Motorcycle(c, g, w, p), make(m) {}

        void displayDetails() {
            cout << "Yamaha Make: " << make << ", Cylinders: " << cylinders << ", Gears: " << gears << ", Wheels: " << wheels << ", Price: " << price << endl;
        }

};

int main() {
    Yamaha yamaha(2, 6, 2, 10000, "Heavy");
    yamaha.displayDetails(); 

    Audi audi(5, 4, "Petrol", 60000, "A6");
    audi.displayDetails();
    
    return 0;
}