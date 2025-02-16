#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Book{
    string author;
    string title;
    double price;
    string publisher;
    int stock;

    public:
    Book(string t, string a, string p, double pr, int s)
    : title(t), author(a), publisher(p), price(pr), stock(s) {}

    void Display() const {
        cout<<"\nDetails\n";
        cout<< "Title: "<<title<<"\nAuthor: "<<author<<"\nPublisher: "<<publisher<<"\nPrice: "<<price<<"\nStock: "<<stock<<"\n"<<endl;
    }
    bool isAvalaible(string t, string a) const {
        return (title == t && author == a);
    }
    void sellBook(int copies){
        if(copies <=stock){
            cout<<"Total Cost: "<<(copies * price)<<endl;
            stock -= copies;
        } else {
            cout<<"Required copies not in stock!"<<endl;
        }
    }
};

class BookShop{
    vector<Book> arr;
    public:
    void addBook(const Book &book){
        arr.push_back(book);
    }
    void findBook(string title, string author, int copies){
        for(auto &book: arr){
            if(book.isAvalaible(title, author)) {
                book.Display();
                //cout<<"Enter number of copies required: "<<copies<<endl;
                book.sellBook(copies);
                return;
            }
        } cout<<"Book not available!"<<endl;
    }

};

int main(){
    BookShop shop;
    shop.addBook(Book("C++ Programming", "ABC", "Pearson", 45.5, 10));
    shop.addBook(Book("OOP", "XYZ", "Pearson", 40.0, 5));

    string title, author;
    int copies;

    cout<<"Enter book title: ";
    getline(cin, title);
    cout<<"Enter author name: ";
    getline(cin, author);
    cout<<"Enter number of copies required: ";
    cin>>copies;

    shop.findBook(title, author, copies);
    return 0;
}