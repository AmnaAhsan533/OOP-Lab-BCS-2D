#include<iostream>
using namespace std;

class Matrix{
    public:
    int rows;
    int cols;
    int elements[rows][cols];

    Matrix(int r, int c){
        rows = r;
        cols = c;
    }

    int getRows(){
        return rows;
    }
    int getCols(){
        return cols;
    }
    void setElements(int rows, int cols, int elements[][]){

    }
    void add(){
        if(rows == cols){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    
                }
            }

        } else {
            cout<<"Matrices cannot be added!"<<endl;
        }
    }
    void multiply(){

    }
};

int main(){

    return 0;
}