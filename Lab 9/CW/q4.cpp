#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Passenger; 

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

    unordered_map<string, string> seatMap; // passengerID -> seatType

public:
    Flight(string fn, string dep, string arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat(const Passenger& p, const string& seatType = "Economy");
    bool cancelSeat(const Passenger& p);
    bool upgradeSeat(const Passenger& p);

    void printStatus() const;
};


class Passenger {
private:
    string name;
    string id;
    
public:
    Passenger(string n, string i) : name(n), id(i) {}
    
    string getID() const { return id; }
    string getName() const { return name; }
    
    void requestBooking(Flight& f, const string& seatType = "Economy") {
        if (f.bookSeat(*this, seatType))
            cout << name << " booked successfully on flight.\n";
        else
            cout << name << " could not book seat.\n";
    }
    
    void requestCancellation(Flight& f) {
        if (f.cancelSeat(*this))
            cout << name << " canceled their seat.\n";
        else
            cout << name << " had no seat to cancel.\n";
    }
    
    void requestUpgrade(Flight& f) {
        if (f.upgradeSeat(*this))
            cout << name << " upgraded successfully.\n";
        else
            cout << name << " could not upgrade (no seat booked).\n";
    }
};

bool Flight::bookSeat(const Passenger& p, const std::string& seatType) {
    if (bookedSeats >= capacity)
        return false;
    if (seatMap.find(p.getID()) != seatMap.end())
        return false; // Already booked

    seatMap[p.getID()] = seatType;
    bookedSeats++;
    return true;
}

bool Flight::cancelSeat(const Passenger& p) {
    auto it = seatMap.find(p.getID());
    if (it == seatMap.end())
        return false;

    seatMap.erase(it);
    bookedSeats--;
    return true;
}

bool Flight::upgradeSeat(const Passenger& p) {
    auto it = seatMap.find(p.getID());
    if (it == seatMap.end())
        return false;

    if (it->second == "Business")
        return false; // Already upgraded

    it->second = "Business";
    return true;
}

void Flight::printStatus() const {
    std::cout << "\nFlight " << flightNumber << " [" << departure << " -> " << arrival << "]\n";
    std::cout << "Capacity: " << capacity << ", Booked: " << bookedSeats << "\n";
    std::cout << "Passengers:\n";
    for (const auto& [id, seat] : seatMap)
        std::cout << "  - ID: " << id << ", Seat: " << seat << "\n";
}

int main() {
    Flight flight1("PK101", "Karachi", "Lahore", 2);
    Passenger p1("Ali", "P001");
    Passenger p2("Sara", "P002");
    Passenger p3("Ahmed", "P003");

    p1.requestBooking(flight1);
    p2.requestBooking(flight1);
    p3.requestBooking(flight1); // Should fail (flight full)

    p2.requestUpgrade(flight1);
    p1.requestCancellation(flight1);
    p3.requestBooking(flight1); // Now possible

    flight1.printStatus();
}
