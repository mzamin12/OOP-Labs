#include <iostream>

class Circle {

private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const {
        return 3.14 * radius * radius;
    }

    double getPerimeter() const {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Circle myCircle(5);
    std::cout << "Area: " << myCircle.getArea() << std::endl;
    std::cout << "Perimeter: " << myCircle.getPerimeter() << std::endl;
    return 0;
}
