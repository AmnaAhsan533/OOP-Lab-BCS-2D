#include<iostream>
using namespace std;

class Book{
    public:
    string name;
    string ISBN;
    string author;
    string publisher;

    string getBookInfo(string name, string ISBN, string author, string publisher){
        this->name = name;
        this->author = author;
        this->ISBN = ISBN;
        this->publisher = publisher;
        
    }
};

int main(){
    Book books[5];

    return 0;
}