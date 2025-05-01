
#include<iostream>
#include<any>
#include<stdexcept>
#include<typeinfo>
using namespace std;

class BadTypeException: public exception{
public:
    const char* what() const noexcept override{
        return "BadTypeException: Type mismatch in TypeSafeContainer.\n";
    }
};

template <typename T>
class TypeSafeContainer{
private:
    any data;
public:
    template <typename U>
    void store(const U& val){
        data = val;
    }

    T get() const {
        try{
            return any_cast<T>(data);
        } 
        catch(const bad_any_cast&){
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer<int> intContainer;
    intContainer.store(123);

    try {
        std::cout << "Retrieved: " << intContainer.get() << "\n";

        // Now try to retrieve the same container as if it stored string
        TypeSafeContainer<std::string> wrongContainer;
        wrongContainer.store(3.14); // even though we store double, type is string

        string result = wrongContainer.get();  //  Throws
        cout << "Should not reach here: " << result << "\n";
    } catch (const BadTypeException& e) {
        cerr << e.what() << "\n";
    }

    return 0;
}
