#include<iostream>
#include<stdexcept>

using namespace std;

class ArrayIndexOutOfBounds: public exception{
public: 
    const char* what() const noexcept override{
        return "Index Out Of Bound!\n";
    }
};

template<typename T>
class SafeArray{
public:
int size;
    T* array;
    SafeArray(int s): size(s) {
        array = new T[size];
    }
    ~SafeArray(){
        delete[] array;
    }
    T& operator[](int index){
        if(index < 0 || index >= size) 
            throw ArrayIndexOutOfBounds();
        return array[index];
    }
    size_t getSize() const {
        return size;
    }
};

int main(){
    try{
        SafeArray<int> sa(5);
        for(int i=0; i<sa.getSize(); i++){
            sa[i] = i*10;
        }
        for (int i = 0; i < sa.getSize(); ++i) {
            cout << sa[i] << " ";
        }
        cout << endl;
        cout << sa[10] << endl; //invalid index
    }
    catch (const ArrayIndexOutOfBounds& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}