#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string modelName;
    float basePrice;

public:
    Car(string model = "", float price = 0.0f) : modelName(model), basePrice(price) {}

    string getModelName() const { return modelName; }
    float getBasePrice() const { return basePrice; }

    void setModelName(string model) { modelName = model; }

    virtual void setFinalPrice(float price) = 0;

    virtual void showDetails() const {
        cout << "Model: " << modelName << " | Final Price: $" << basePrice << endl;
    }

    virtual ~Car() {}
};

class ColorVariant : public Car {
private:
    string colorName;

public:
    ColorVariant(string model, float price, string color) : Car(model, price), colorName(color) {}

    void setColorName(string color) { colorName = color; }
    string getColorName() const { return colorName; }

    void setFinalPrice(float price) override {
        basePrice = price + (price * 0.07f); // 7% extra for color variant
    }

    void showDetails() const override {
        Car::showDetails();
        cout << "Color: " << colorName << endl;
    }
};

class Manufacturer : public Car {
private:
    string companyName;

public:
    Manufacturer(string model, float price, string company) : Car(model, price), companyName(company) {}

    void setCompanyName(string company) { companyName = company; }
    string getCompanyName() const { return companyName; }

    void setFinalPrice(float price) override {
        basePrice = price + 1200; // $1200 extra for brand/manufacturer value
    }

    void showDetails() const override {
        Car::showDetails();
        cout << "Brand: " << companyName << endl;
    }
};

int main() {
    ColorVariant car1("Hatchback", 18000, "Midnight Blue");
    car1.setFinalPrice(18000);
    cout << "=== Color Variant ===" << endl;
    car1.showDetails();

    cout << endl;

    Manufacturer car2("Crossover", 26000, "Hyundai");
    car2.setFinalPrice(26000);
    cout << "=== Manufacturer Variant ===" << endl;
    car2.showDetails();

    return 0;
}
