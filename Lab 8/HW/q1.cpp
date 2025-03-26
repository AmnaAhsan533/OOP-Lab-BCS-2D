#include<iostream>
using namespace std;

class Absurd{
    int x;
    public:
   
    Absurd(int x) : x(x) {}
    Absurd& operator--(){ //prefix --x
        x *= 4;
        return *this;
    }
    Absurd operator--(int){ //postfix x--
        Absurd temp = *this;
        x /= 4;
    
        return temp;
    }
    void display(){
        cout<<"x: "<< x <<endl;
    }
};

int main(){
    Absurd ex(4);
    cout << "Initial: ";
    ex.display();
    --ex;
    cout << "After --x: ";
    ex.display();
    //ex--.display();
    cout << "After x--: ";
    ex.display();

    return 0;
}
