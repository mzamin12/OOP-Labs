#include <iostream>

using namespace std;

class Integer {
private:
    int data;
public:
    Integer(int d) : data(d) {}

    Integer& operator--() {
        data *= 4;
        return *this;
    }

    Integer operator--(int) {
        Integer temp = *this;
        data /= 4;
        return temp;
    }

    void show() const {
        cout << "Current Value: " << data << endl;
    }
};

int main() {
    Integer num(8);

    cout << "Initial: ";
    num.show();

    --num;
    cout << "Updated: ";
    num.show();

    num--;
    cout << "Final: ";
    num.show();

    return 0;
}
