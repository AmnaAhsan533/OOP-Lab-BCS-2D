#include<iostream>
#include<vector>

using namespace std;

class Matrix{
    int rows, cols;
    double* values;
   
public:
    //Default Constructor
    Matrix(){
        rows = 0;
        cols = 0;
        values = nullptr;
    }
    //Parameterized Constructor
    Matrix(int r, int c){
        rows = r;
        cols = c;
        values = new double [ rows * cols]();
    }
    //Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        values = new double[rows * cols];
        for(int i=0; i<rows*cols; i++){
            values[i] = other.values[i];
        }
    }
    //Move Constructor
    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), values(other.values){
        other.values = nullptr;
        other.rows = other.cols = 0;
    }
    //Destructor
    ~Matrix(){
        delete[] values;
    }
    int getRows(){
        return rows;
    }
    int getCols(){
        return cols;
    }
    double& at(int r, int c) const {
        if(r < 0 || r>= rows || c < 0 || c >= cols){
            cout<<"Invalid index!"<<endl;
        }
        return values[r * cols + c];
    }

    void fill(double value){
        for(int i=0; i<rows*cols; i++){
            values[i] = value;
        }
    }
    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                transposed.at(c, r) = at(r, c);
            }
        }
        return transposed;
    }

    void print() const {
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                cout<<" "<<at(r, c)<<" ";
            }
            cout<<"\n";
        }
    }

};

int main(){
    Matrix A;
    cout<<"Default Matrix (0 x 0):\n";
    cout<<"Rows: "<<A.getRows()<<" Cols: "<<A.getCols()<<"\n";

    Matrix B(3, 3);
    cout<<"Parameterized Constructor";
    B.fill(5.0);
    B.print();
    cout<<endl;

    Matrix C = B;
    cout<<"Copied Matrix C from B:\n";
    C.print();
    cout<<endl;

    Matrix D = move(B);
    cout<<"Moved Matrix D from B:\n";
    D.print();
    cout<<endl;

    Matrix E = D.transpose();
    cout<<"Transpose Matrix:\n";
    E.print();
    cout<<endl;


    return 0;
}