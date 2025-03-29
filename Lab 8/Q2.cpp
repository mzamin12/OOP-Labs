#include <iostream>

using namespace std;

class Figure {
private:
    double size;
public:
    Figure(double s = 0) : size(s) {}

    double computeSize() const {
        return size * 1.1;
    }

    Figure operator+(const Figure& other) const {
        return Figure(this->computeSize() + other.computeSize());
    }

    void show() const {
        cout << "Calculated Size: " << computeSize() << endl;
    }
};

int main() {
    Figure fig1(20.5), fig2(15.3);
    
    Figure totalSize = fig1 + fig2;

    cout << "Figure 1: ";
    fig1.show();

    cout << "Figure 2: ";
    fig2.show();

    cout << "Total: ";
    totalSize.show();

    return 0;
}
