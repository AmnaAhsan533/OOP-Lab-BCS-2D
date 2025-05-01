#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

class DimensionMismatch: public exception{
public:
    const char* what() const noexcept override{
        return "Dimension Mismatch Exception: Matrix dimensions do not match for this operation!\n";
    }
};

template<typename T>
class Matrix{
private:
    int rows, cols;
    vector<vector<T>> data;
public:
    Matrix(int r, int c, const T& initial = T()): rows(r), cols(c), data(r, vector<T>(c, initial)) {}
    
    
    T& at(int r, int c){
        if(r >= rows || c >= cols){
            throw out_of_range("Index out of bounds.");
        }
        return data[r][c];
    }
    Matrix<T> operator+(const Matrix<T> & other) const {
        if(rows!= other.rows || cols!= other.cols) throw DimensionMismatch();
        Matrix<T> result(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix<T> operator*(const Matrix<T>& other){
        if(cols!=other.rows) throw DimensionMismatch();
        Matrix<T> result(rows, other.cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<other.cols; j++)
                for(int k=0; k<cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A.at(0, 0) = 1; A.at(0, 1) = 2;
        A.at(1, 0) = 3; A.at(1, 1) = 4;

        B.at(0, 0) = 5; B.at(0, 1) = 6;
        B.at(1, 0) = 7; B.at(1, 1) = 8;

        Matrix<int> C = A + B;
        Matrix<int> D = A * B;

        cout << "A + B = \n"; C.print();
        cout << "\nA * B = \n"; D.print();
    }
    catch (const DimensionMismatch& e) {
        std::cerr << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
