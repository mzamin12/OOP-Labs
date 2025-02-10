#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **elements;

public:
    void setSize(int r, int c) {
        rows = r;
        cols = c;
        elements = new int *[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                elements[i][j] = 0;
            }
        }
    }

    void freeMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix &other) {
        Matrix result;
        if (this->rows != other.rows || this->cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            result.setSize(0, 0);
            return result;
        }

        result.setSize(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = this->elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix &other) {
        Matrix result;
        if (this->cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            result.setSize(0, 0);
            return result;
        }

        result.setSize(this->rows, other.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.elements[i][j] = 0;
                for (int k = 0; k < this->cols; k++) {
                    result.elements[i][j] += this->elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix mat1, mat2;
    mat1.setSize(2, 2);
    mat2.setSize(2, 2);

    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(1, 0, 3);
    mat1.setElement(1, 1, 4);

    mat2.setElement(0, 0, 5);
    mat2.setElement(0, 1, 6);
    mat2.setElement(1, 0, 7);
    mat2.setElement(1, 1, 8);

    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "\nMatrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1.add(mat2);
    cout << "\nSum of Matrices:" << endl;
    sum.display();

    Matrix product = mat1.multiply(mat2);
    cout << "\nProduct of Matrices:" << endl;
    product.display();

    mat1.freeMemory();
    mat2.freeMemory();
    sum.freeMemory();
    product.freeMemory();

    return 0;
}
