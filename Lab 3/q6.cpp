#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> elements; 

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        elements = vector<vector<int>>(r, vector<int>(c, 0));
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            elements[i][j] = value;
        else
            cout << "Invalid index!\n";
    }

    void printMatrix() const {
        for (const auto &row : elements) {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    }

    Matrix add(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added\n";
            return Matrix(0, 0); // Return empty matrix
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.elements[i][j] = elements[i][j] + other.elements[i][j];

        return result;
    }

    Matrix multiply(const Matrix &other) const {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied\n";
            return Matrix(0, 0); 
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];

        return result;
    }
};

int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    cout << "Matrix A:\n";
    A.printMatrix();
    
    cout << "\nMatrix B:\n";
    B.printMatrix();

    cout << "\nMatrix A + B:\n";
    Matrix C = A.add(B);
    C.printMatrix();

    cout << "\nMatrix A * B:\n";
    Matrix D = A.multiply(B);
    D.printMatrix();

    return 0;
}
