#include<iostream>
#include<vector>
using namespace std;

class Book{
    public:
    string title;
    string author;
    string isbn;

    Book(const string& t, const string& a, const string& isbn ): title(t), author(a), isbn(isbn) {}

};

class Catalog{
    vector<Book*>books;
    public:
    Catalog() {
        cout << "Catalog is automatically created inside the Library.\n";
    }
    void addBook(Book *book){
        books.push_back(book);
    }

    void removeBook(const string& isbn){
        for(int i=0; i<books.size(); i++){
            if(books[i]->isbn == isbn){
                books.erase(books.begin() + i);
                return;
            }  
        }
    }
    Book* findBook(const string& isbn){
        for(auto book: books){
            if(book->isbn == isbn){
                return book;
            }
        }
        return nullptr;
    }
};

class Library{
    vector<Book*>books;
    Catalog catalog;
    string name;
    string address;
    public:
    Library(const string& n, const string& add): name(n), address(add) {}

    void addBook(Book* book){
        books.push_back(book);
        catalog.addBook(book);
    }
    void removeBook(const string& isbn){
        catalog.removeBook(isbn);
        for(int i=0; i<books.size(); i++){
            if(books[i]->isbn == isbn){
                books.erase(books.begin()+ i);
                return;
            }
        }
    }
    Book* findBookInCatalog(const string& isbn){
        return catalog.findBook(isbn);
    }
    void displayBooks(){
        cout<<"Books in Library\n";
        for(const auto& book: books){
            cout<<"Tiltle: "<<book->title<<"\nAuthor: "<<book->author<<"\nISBN: "<<book->isbn<<endl;
        }
    }
};

int main() {
    Library library("Central Library", "123 Main St");
    
    Book* book1 = new Book("Object Oriented Programming", "ABC", "1234");
    Book* book2 = new Book("Data Structures and Algorithms", "XYZ", "5678");

    library.addBook(book1);
    library.addBook(book2);
  
    library.displayBooks();
 
    string searchISBN = "1234";
    Book* foundBook = library.findBookInCatalog(searchISBN);
    if (foundBook) {
        cout << "Found Book: " << foundBook->title << " by " << foundBook->author << "\n";
    } else {
        cout << "Book with ISBN " << searchISBN << " not found.\n";
    }

    library.removeBook("5678");
    std::cout << "After removal:\n";
    library.displayBooks();

    delete book1;
    delete book2;
    
    return 0;
}