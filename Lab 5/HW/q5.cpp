#include<iostream>
using namespace std;

class Car{
    public:
    mutable int engine_hp;
    mutable int seating_cap;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers): engine_hp(hp), seating_cap(seats), no_of_speakers(speakers) {}
    
    void changeHP(int new_hp) const {
        engine_hp = new_hp;
    }
    void changeCapacity(int new_cap) const {
        seating_cap = new_cap;
    }
    void changeSpeakers(int new_speaker) const{
        no_of_speakers = new_speaker;
    }
    void display() const {
        cout << "Engine Horsepower: " << engine_hp << "\n";
        cout << "Seating Capacity: " << seating_cap << "\n";
        cout << "Number of Speakers: " << no_of_speakers << "\n";
    }

};


int main() {
    Car myCar(200, 5, 4); 
    myCar.display();

    myCar.changeSpeakers(6);
    myCar.changeCapacity(10);
    myCar.changeHP(300); 
    cout << "\nAfter modifications:\n";
    myCar.display();

    return 0;
}