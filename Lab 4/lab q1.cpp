#include <iostream>
#include <stdexcept>

class Matrix {
private:
    double** mat;
    int rows;
    int cols;

public:
    Matrix() : rows(0), cols(0), mat(nullptr) {}

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new double[cols]();
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        mat = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), mat(other.mat) {
        other.rows = 0;
        other.cols = 0;
        other.mat = nullptr;
    }

    ~Matrix() {
        if (mat) {
            for (int i = 0; i < rows; ++i) {
                delete[] mat[i];
            }
            delete[] mat;
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
           std::cout << "Invalid index \n";
        }
        return mat[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.mat[j][i] = mat[i][j];
            }
        }
        transposed.print();
        return transposed;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
};

int main() {
    Matrix m1(2, 3);
    m1.fill(5.0);
    std::cout << "Original matrix:" << '\n';
    m1.print();
    std::cout << "Transposed matrix:" << '\n';
    Matrix m2 = m1.transpose();
    return 0;
}