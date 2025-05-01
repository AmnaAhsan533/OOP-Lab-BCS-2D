#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

class StackUnderflowException: public exception{
public:
    const char* what() const noexcept override{
        return "Stack Underflow: Stack is empty!";
    }
};

template<typename T>
class Stack{
    vector<T> data;
public:
    void push(T value){
        data.push_back(value);
    }
    void pop() {
        if(data.empty()){
            throw StackUnderflowException();
        }
        data.pop_back();
    }
    T top(){
        if(data.empty()){
            throw StackUnderflowException();
        }
        return data.back();
    }

};

int main(){
    Stack<int> s;
    try{
        s.push(10);
        s.push(20);
        cout << "Top element: " << s.top() << endl;

        s.pop();
        cout << "Top element after pop: " << s.top() << endl; // 10
        s.pop();
        s.pop(); //invalid
    }
    catch (const StackUnderflowException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}