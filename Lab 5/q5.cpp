#include <iostream>
#include <windows.h>
using namespace std;

class Car {
private:
    mutable float engineHorsepower;
    mutable int seatingCapacity;
    mutable int numberOfSpeakers;

public:
    Car() : engineHorsepower(0), seatingCapacity(0), numberOfSpeakers(0) {}

    void setEngineHorsepower(float hp) const 
    { 
        engineHorsepower = hp; 
    }
    
    void setSeatingCapacity(int capacity) const 
    { 
        seatingCapacity = capacity; 
    }
    
    void setNumberOfSpeakers(int speakers) const 
    { 
        numberOfSpeakers = speakers; 
    }

    float getEngineHorsepower() const 
    { 
        return engineHorsepower; 
    }
    
    int getSeatingCapacity() const 
    { 
        return seatingCapacity; 
    }
    
    int getNumberOfSpeakers() const 
    { 
        return numberOfSpeakers; 
    }

    void display() const {
        cout << "Current Engine Power: " << getEngineHorsepower() << " HP" << endl;
        cout << "Seating for: " << getSeatingCapacity() << " people" << endl;
        cout << "Equipped with " << getNumberOfSpeakers() << " speakers" << endl;

        Sleep(5000);  
        system("cls"); 
    }
};

int main() {
    Car myCar;

    cout << "Displaying car's initial specs:\n";
    myCar.display();

    myCar.setEngineHorsepower(500);
    myCar.setSeatingCapacity(10);
    myCar.setNumberOfSpeakers(2);

    cout << "Updated car specifications:\n";
    myCar.display();

    cout << "Thank you for using our system!" << endl;
    Sleep(5000);
    return 0;
}
