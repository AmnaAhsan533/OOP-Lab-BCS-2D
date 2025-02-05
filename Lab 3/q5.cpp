#include<iostream>
using namespace std;

class Book{
    public:
    string name;
    string ISBN;
    string author;
    string publisher;

    Book(){} //default constructor
    Book(string name, string ISBN, string author, string publisher){
        this->name = name;
        this->author = author;
        this->ISBN = ISBN;
        this->publisher = publisher;       
    }
    string getBookName(){
        return name;
    }
    string getISBN(){
        return ISBN;
    }
    string getAuthor(){
        return author;
    }
    string getPublisher(){
        return publisher;
    }
    string getBookInfo() const{
        return "Book Name: "+ name +"\nISBN: "+ ISBN +"\nAuthor: "+author +"\nPublisher: "+ publisher +"\n";
    }
};

int main(){
    Book books[5]={
        Book("C", "123", "XYZ", "ABC-PUB"),
        Book("C++", "456", "ABC", "DEF-PUB"),
        Book("Java", "789", "LMN", "GHI-PUB"),
        Book("Python", "321", "PQR", "JKL-PUB"),
        Book("JavaScript", "654", "UVW", "MNO-PUB")
    };

    for(const auto& book: books){
        cout<<book.getBookInfo()<<"\n";
    }
    

    return 0;
}
