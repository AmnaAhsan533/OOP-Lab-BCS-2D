#include<iostream>
using namespace std;

class DynamicArray{
    int *arr;
    int size;
    public:
    DynamicArray(): arr(nullptr), size(0) { }
    DynamicArray(int n): size(n) {
        arr = new int[size]{0};
    }
    DynamicArray(const DynamicArray& other): size(other.size) {
        arr = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = other.arr[i];
        }
    }
    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), size(other.size) {
        other.arr = nullptr;
    }
    DynamicArray& operator=(const DynamicArray& other){
        if(this != &other){
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for(int i=0; i<size; i++){
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if(this != &other){
            delete[] arr;
            arr = other.arr;
            other.arr = nullptr;
            other.size = 0;
        }
        return *this;
    }
    ~DynamicArray() {
        delete[] arr;
    }
    int getSize(){ return size; }
    int& at(int index){
        if(index < 0 || index >= size){
            cout<<"Index out of bounds!";
        }
        return arr[index];
    }
    const int& at(int index) const{
        if(index < 0 || index >= size){
            cout<<"Index out of bounds!";
        }
        return arr[index];
    }
    void resize(int newSize){
        if(newSize < 0){
            cout<<"Size cannot be negative!";
            return;
        }
        int *newarr = new int[newSize]{};
        int copySize = (newSize < size)? newSize : size;
        for(int i=0; i<copySize; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        size = newSize;
    }
    void display() const{
        for(int i=0; i<size; i++){
            cout<<arr[i] <<" ";
        }cout<<endl;
    }
};

int main(){
    DynamicArray arr(5);
    arr.at(0) = 10;
    arr.at(1) = 20;
    arr.display();
    DynamicArray copyarr = arr;
    copyarr.display();

    DynamicArray movedarr = move(arr);
    movedarr.display();
    movedarr.resize(7);
    movedarr.display();
    return 0;

}