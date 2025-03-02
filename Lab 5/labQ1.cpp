#include <iostream>
using namespace std;

class Engine {
public:
    void initialize() {
        cout << "Engine Started" << endl;
    }

    void terminate() {
        cout << "Engine Stopped" << endl;
    }

    ~Engine() {
    }
};

class Car {
private:
    Engine engineComponent;

public:
    void activate() {
        engineComponent.initialize();
    }

    void deactivate() {
        engineComponent.terminate();
    }

    ~Car() {
    }
};

int main() {
    Car vehicle;
    vehicle.activate();
    vehicle.deactivate();

    return 0;
}