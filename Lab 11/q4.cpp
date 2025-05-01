#include<iostream>

using namespace std;

template<typename T>
class Base{
protected:
    T val1, val2;
public:
    Base(T v1, T v2): val1(v1), val2(v2) {}
    void multiplyB(){
        cout<< "Base Multiply: "<<val1 * val2<<endl;
    }
    
};

template<typename T, typename U>
class Derived: public Base<T>{
protected:
    U x, y;
public:
    Derived(T v1, T v2, U a, U b): Base<T>(v1, v2), x(a), y(b) {}
    void multiplyD() {
        cout<<"Derived Multiply: "<<x * y<< endl;
    }
    
};

int main(){
    Derived<int, int> obj(2, 3, 4, 5);
    obj.multiplyD();
    obj.multiplyB();

    return 0;
}