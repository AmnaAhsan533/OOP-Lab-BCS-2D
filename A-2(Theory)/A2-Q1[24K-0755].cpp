#include <iostream>
#include <string>
using namespace std;

const int MEMBERS = 50;
const int MAX_STOPS = 10;
const int MAX_BUSES = 20;

class Member {
protected:
    string name, id, assignedStop;
    bool feeStatus, cardStatus;
public:
    Member(const string &id, const string &n) 
    : id(id), name(n), feeStatus(false), cardStatus(false) {}
    virtual ~Member() {}
    virtual void payFees(double amount) = 0;
    string getName() const { return name; }
    bool isFeePaid() const { return feeStatus; }
};

class Student : public Member {
private:
    int attendanceCount;
public:
    Student(const string &id, const string &n) 
    : Member(id, n), attendanceCount(0) {}
    void payFees(double amount) override {
        if (amount >= 50000) { // Assume semester fee is 50000
            feeStatus = true;
            cardStatus = true;
        }
    }
    void markAttendance() { if (cardStatus) attendanceCount++; }
};

class Teacher : public Member {
public:
    Teacher(const string &id, const string &n) : Member(id, n) {}
    void payFees(double amount) override {
        if (amount >= 5000) { // Assume monthly fee is 5000
            feeStatus = true;
        }
    }
};

class Staff : public Member {
public:
    Staff(const string &id, const string &n) : Member(id, n) {}
    void payFees(double amount) override {
        if (amount >= 3000) { // Assume monthly fee for staff is 3000
            feeStatus = true;
        }
    }
};

class Stop {
private:
    string stopName;
public:
    Stop(string name) : stopName(name) {}
    string getStopName() const { return stopName; }
};

class Route {
private:
    string routeName;
    Stop* stops[MAX_STOPS];
    int numStops;
public:
    Route(string name) : routeName(name), numStops(0) {}
    void addStop(Stop* stop) {
        if (numStops < MAX_STOPS) {
            stops[numStops++] = stop;
        }
    }
    bool operator==(const Route &other) const {
        if (numStops != other.numStops) return false;
        for (int i = 0; i < numStops; i++) {
            if (stops[i]->getStopName() != other.stops[i]->getStopName()) return false;
        }
        return true;
    }
    bool operator!=(const Route &other) const {
        return !(*this == other);
    }
};

class Bus {
private:
    int busNo;
    Route* route;
public:
    Bus(int no, Route* r) : busNo(no), route(r) {}
};

class TransportationSystem {
private:
    Member* members[MEMBERS];
    int memCount;
    Route* routes[MAX_STOPS];
    int routeCount;
    Bus* buses[MAX_BUSES];
    int busCount;
public:
    TransportationSystem() : memCount(0), routeCount(0), busCount(0) {}
    ~TransportationSystem() {
        for (int i = 0; i < memCount; i++) delete members[i];
        for (int i = 0; i < routeCount; i++) delete routes[i];
        for (int i = 0; i < busCount; i++) delete buses[i];
    }
    void registerMember(const string &id, const string &name) {
        if (memCount < MEMBERS) {
            members[memCount++] = new Student(id, name);
            cout<<name<<" registered successfully\n";
        }
    }
    void createRoute(const string &routeId, string stopNames[], int numStops) {
        if (routeCount < MAX_STOPS) {
            Route* newRoute = new Route(routeId);
            for (int i = 0; i < numStops; i++) {
                newRoute->addStop(new Stop(stopNames[i]));
            }
            routes[routeCount++] = newRoute;
            cout<<"Stops added successfully to route: "<<routeId<<endl;
        }
    }
};

int main() {
    cout<<"Amna Ahsan\nID: 24K-0755\n";
    TransportationSystem system;
    system.registerMember("24K-0755", "Amna");
    system.registerMember("24K-1013", "Aisha");
    string stops[] = {"Quidabad", "Malir Halt", "Shama"};
    system.createRoute("Malir", stops, 3);
   
    Route route1("Malir"), route2("Malir");
    route1.addStop(new Stop("Quidabad"));
    route1.addStop(new Stop("Malir Halt"));
    route1.addStop(new Stop("Shama"));
    
    route2.addStop(new Stop("Quidabad"));
    route2.addStop(new Stop("Malir Halt"));
    route2.addStop(new Stop("Shama"));
    
    if (route1 == route2) {
        cout << "The routes are the same." << endl;
    } else {
        cout << "The routes are different." << endl;
    }
    return 0;
}
