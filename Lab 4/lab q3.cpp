#include <iostream>

class DynamicArray {
private:
    int* data;
    int length;

public:
    DynamicArray() : data(nullptr), length(0) {}

    DynamicArray(int n) : length(n), data(new int[n]{}) {}


    DynamicArray(const DynamicArray& other) : length(other.length), data(new int[other.length]) {
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    ~DynamicArray() { delete[] data; }

    int size() const { return length; }

    int& at(int index) { return data[index]; }

    const int& at(int index) const { return data[index]; }

    void resize(int newSize) {
        int* newData = new int[newSize]{};
        int minSize = (newSize < length) ? newSize : length;
        for (int i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        length = newSize;
    }

    void display() const {
        for (int i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.at(0) = 10;
    arr1.at(1) = 20;
    arr1.at(2) = 30;
    arr1.at(3) = 40;
    arr1.at(4) = 50;
    
    std::cout << "Initial array: ";
    arr1.display();
    
    DynamicArray arr2 = arr1;
    std::cout << "Copied array: ";
    arr2.display();
    
    DynamicArray arr3 = std::move(arr1);
    std::cout << "Moved array: ";
    arr3.display();
    
    arr3.resize(7);
    std::cout << "Resized array: ";
    arr3.display();
    
    return 0;
}