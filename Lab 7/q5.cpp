#include<iostream>
#include <vector>
using namespace std;

class Media{
    protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isAvailable;
    public:
    Media(string t, string pubDate, string id, string pub)
    : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isAvailable(true) {}

virtual void displayInfo() {
    cout << "Title: " << title << "\nPublication Date: " << publicationDate
         << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
         << "\nAvailability: " << (isAvailable ? "Available" : "Checked Out") << endl;
}

virtual void checkOut() {
    if (isAvailable) {
        isAvailable = false;
        cout << title << " has been checked out." << endl;
    } else {
        cout << title << " is currently unavailable." << endl;
    }
}

virtual void returnItem() {
    isAvailable = true;
    cout << title << " has been returned." << endl;
}

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
};
class Book : public Media {
    private:
        string author, ISBN;
        int numberOfPages;
    public:
        Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
            : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}
        
        void displayInfo() override {
            cout<<"---Book Info---\n";
            Media::displayInfo();
            cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
        }
    };
    
    class DVD : public Media {
    private:
        string director;
        double duration;
        string rating;
    public:
        DVD(string t, string pubDate, string id, string pub, string dir, double dur, string rate)
            : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}
        
        void displayInfo() override {
            cout<<"---DVD Info---\n";
            Media::displayInfo();
            cout << "Director: " << director << "\nDuration: " << duration << " hrs\nRating: " << rating << endl;
        }
    };
    
    class CD : public Media {
    private:
        string artist, genre;
        int numberOfTracks;
    public:
        CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
            : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
        
        void displayInfo() override {
            cout<<"---CD Info---\n";
            Media::displayInfo();
            cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
        }
    };
    
    class Library {
    private:
        vector<Media*> collection;
    public:
        void addMedia(Media* item) {
            collection.push_back(item);
        }
        
        void searchMedia(string title) {
            for (auto media : collection) {
                if (media->getTitle() == title) {
                    media->displayInfo();
                    return;
                }
            }
            cout << "Media not found." << endl;
        }
        
        void searchMedia(string title, string publicationDate) {
            for (auto media : collection) {
                if (media->getTitle() == title && media->getPublicationDate() == publicationDate) {
                    media->displayInfo();
                    return;
                }
            }
            cout << "Media not found." << endl;
        }
    };
    
    int main() {
        Library lib;
        
        Book book("C++ Programming", "2020", "B101", "TechPress", "John Doe", "123-456-789", 500);
        DVD dvd("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 2.5, "PG-13");
        CD cd("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", 9, "Pop");
        
        lib.addMedia(&book);
        lib.addMedia(&dvd);
        lib.addMedia(&cd);
        
        cout << "--- Library Collection ---\n";
        book.displayInfo();
        dvd.displayInfo();
        cd.displayInfo();
        
        cout << "\n--- Searching for 'Inception' ---\n";
        lib.searchMedia("Inception");
        
        cout << "\n--- Searching for 'C++ Programming' published in 2020 ---\n";
        lib.searchMedia("C++ Programming", "2020");
    

        cout << "\n--- Checking Out 'C++ Programming' ---\n";
        book.checkOut();
        
        cout << "\n--- Returning 'C++ Programming' ---\n";
        book.returnItem();
        
        return 0;
    }
    