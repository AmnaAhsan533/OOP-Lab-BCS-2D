
#include<iostream>
using namespace std;

class Books{
    public:
    string genre;
    Books(string g): genre(g){}
    
};

class Mystery: public Books{
    public:
    string title;
    string author;
    Mystery(string t, string a): title(t), author(a), Books("Mystery") {}
    void displayBook(){
        cout<<"Genre: "<<genre<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout << "------------------------" << endl;
    }
};

class Novel: public Books{
    public:
    string title;
    string author;
    Novel(string t, string a): title(t), author(a), Books("Novel") {}
    void displayBook(){
        cout<<"Genre: "<<genre<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout << "------------------------" << endl;
    }
};

int main(){
    Mystery b1("Gone Girl", "Gillian Flynn");
    Novel b2("Nineteen Eighty-Four", "George Orwell");

    b1.displayBook();
    b2.displayBook();
}
