#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_STOPS = 10;
const int MAX_BUSES = 20;

class Student {
private:
    string name;
    string stdID;
    string assignedStop;
    int attendanceCount;
    bool feeStatus;
    bool cardStatus;

public:
    Student(const string &id, const string &n) 
        : stdID(id), name(n), assignedStop(""),
         attendanceCount(0), feeStatus(false), cardStatus(false) {}
    ~Student(){}

    string getName() const { return name; }
    string getID() const { return stdID; }
    string getStop() const { return assignedStop; }
    bool isCardActive() const { return cardStatus; }
    bool isFeePaid() const { return feeStatus; }
    int getAttendance() const { return attendanceCount; }

    void PayFees(){
        feeStatus = true;
        cardStatus = true;
    }
    void markAttendance(){
        if(cardStatus){
            attendanceCount++;
        }        
    }
    void assignStop(const string &stop) {
        assignedStop = stop;
    }
};
class Stop {
private:
    string stopName;
    string* assignedStudents;
    int studentCount;
    int capacity;
public:
    Stop(string name): stopName(name), capacity(MAX_STUDENTS),
     studentCount(0) {
        assignedStudents = new string[capacity];
    }
    ~Stop(){
        delete[] assignedStudents;
    }
    string getStopName() const { return stopName; }
    int getStudentCount() const { return studentCount; }
    string getStudentAtIndex(int index) const {
        if(index >= 0 && index < studentCount)
            return assignedStudents[index];
        else return ""; }
    void addStudent(const string &student_id){
        if(studentCount < capacity)
            assignedStudents[studentCount++] = student_id;
        else cout << "Stop " << stopName << " is at full capacity!" << endl;           
    }
    void removeStudent(const string &student_id){
        int index = -1;
        for(int i = 0; i < studentCount; i++){
            if(assignedStudents[i] == student_id){
                index = i;
                break;
            }
        }
        if(index != -1){
            for(int i = index; i < studentCount - 1; i++){
                assignedStudents[i] = assignedStudents[i+1];
            }
            studentCount--;
        }
    }
};

class Route {
private:
    string routeName;
    Stop** stops;
    int numStops;
    int capacity;
public:
    Route(string name): routeName(name), numStops(0), capacity(MAX_STOPS){
        stops = new Stop*[capacity];  }
    ~Route(){
        for(int i = 0; i < numStops; i++) { delete stops[i]; }
        delete[] stops;
    }
    string getRouteName() const { return routeName; }
    int getNumStops() const { return numStops; }
    Stop* getStopAtIndex(int index) const {
        if(index >= 0 && index < numStops){
            return stops[index];
        }
        return nullptr;
    }
    void addStop(Stop* stop){
        if(numStops < capacity)
            stops[numStops++] = stop;
        else
            cout << "Cannot add more stops to route " << routeName << "!" << endl;
    }
};

class Bus {
private:
    int pointNo;
    Route* route;
    static const int capacity;
public:
    Bus(int no, Route* r): pointNo(no), route(r) {}
    ~Bus() {}

    int getBusID() const { return pointNo; }
    Route* getRoute() const { return route; }
    static int getCapacity() {
        return capacity;
    }

    void tapCard(Student* std){
        if(std->isCardActive()) {
            std->markAttendance();
            cout << "Attendance recorded for " << std->getName() << endl;
        } else {
            cout<<"Card inactive for "<<std->getName()<<". Payment required!"<<endl;
        }
    }
};
const int Bus::capacity = 50;

class TransportationSystem {
private:
    Student** students;
    int studentCount;
    int studentCapacity;
    Route** routes;
    int routeCount;
    int routeCapacity;
    Bus** buses;
    int busCount;
    int busCapacity;
public:
    TransportationSystem(){
        studentCapacity = MAX_STUDENTS;
        studentCount = 0;
        students = new Student*[studentCapacity];
        routeCapacity = MAX_STOPS; 
        routeCount = 0;
        routes = new Route*[routeCapacity];
        busCapacity = MAX_BUSES;
        busCount = 0;
        buses = new Bus*[busCapacity];
    }
    ~TransportationSystem() {
        for (int i = 0; i < studentCount; i++)
            delete students[i];
        delete[] students;

        for (int i = 0; i < routeCount; i++)
            delete routes[i];
        delete[] routes;

        for (int i = 0; i < busCount; i++)
            delete buses[i];
        delete[] buses;
    }
    void registerStudent(const string &stdID, const string &name){
        if(studentCount < studentCapacity){
            Student* newStd = new Student(stdID, name);
            students[studentCount++] = newStd;
            cout << "Student " << name << " registered successfully." << endl;
        } else {
            cout << "Student capacity reached." << endl;
        }
    }
    void paySemesterFee(const string &stdID){
        Student* student = findStudent(stdID);
        if(student){
            student->PayFees();
            cout << "Semester fee paid for " << student->getName() << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }
    void createRoute(const string routeId, const string stopNames[], int numStops){
        if(routeCount < routeCapacity){
            Route* newRoute = new Route(routeId);
            for(int i = 0; i < numStops; i++){
                Stop* st = new Stop(stopNames[i]);
                newRoute->addStop(st);
            }
            routes[routeCount++] = newRoute;
            cout << "Route " << routeId << " created successfully." << endl;
        } else {
            cout << "Route capacity reached." << endl;
        }
    }
    void createBus(const int &busId, const string &routeId){
        Route* route = findRoute(routeId);
        if (route){
            if(busCount < busCapacity){
                Bus* newBus = new Bus(busId, route);
                buses[busCount++] = newBus;
                cout<<"Bus "<<busId<<" assigned to route "<<routeId<<"."<<endl;
            } else {
                cout << "Bus capacity reached." << endl;
            }
        } else cout << "Route " << routeId << " not found." << endl;
    }
    void assignStudentToStop(const string &stdId, const string &stopId){
        Student* student = findStudent(stdId);
        if (student) {
            student->assignStop(stopId);
            cout<<"Student "<<student->getName()<<" assigned to stop "<<stopId<<"."<<endl;
            Stop* stop = findStop(stopId);
            if (stop)
                stop->addStudent(stdId);
            else
                cout << "Stop " << stopId << " not found." << endl;
        } else cout << "Student not found." << endl;
    }

    void tapCard(const int &busId, const string &stdId){
        Bus* bus = findBus(busId);
        Student* student = findStudent(stdId);
        if (bus && student) {
            bus->tapCard(student);
        } else cout << "Bus or Student not found." << endl;
    }
    Student* findStudent(const string &studentID) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == studentID)
                return students[i];
        } return nullptr;
    }
    Route* findRoute(const string &routeID) {
        for (int i = 0; i < routeCount; i++) {
            if (routes[i]->getRouteName() == routeID)
                return routes[i];
        } return nullptr;
    }
    Bus* findBus(const int &busID) {
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->getBusID() == busID)
                return buses[i];
        } return nullptr;
    }
    Stop* findStop(const string &stopID) {
        for (int i = 0; i < routeCount; i++) {
            Route* route = routes[i];
            for (int j = 0; j < route->getNumStops(); j++) {
                Stop* stop = route->getStopAtIndex(j);
                if (stop && stop->getStopName() == stopID)
                    return stop;
            }
        }
        return nullptr;
    }
    void displayRegisteredStudents() {
        cout << "\n=== Registered Student Records ===\n";
        if(studentCount == 0) {
            cout << "No students registered.\n";
            return;
        }
        for(int i = 0; i < studentCount; i++){
            Student *s = students[i];
            cout << "Student ID: " << s->getID() 
                 << ", Name: " << s->getName() 
                 << ", Fee: " << (s->isFeePaid() ? "Paid" : "Not Paid") 
                 << ", Card: " << (s->isCardActive() ? "Active" : "Inactive")
                 << ", Assigned Stop: " << s->getStop()
                 << ", Attendance: " << s->getAttendance() << endl;
        }
    }
};
void displayMainMenu() {
    cout << "\n==== Main Menu ====\n";
    cout << "Select Role:\n";
    cout << "1. Student\n";
    cout << "2. Admin\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void displayStudentMenu() {
    cout << "\n==== Student Menu ====\n";
    cout << "1. Register Student\n";
    cout << "2. Pay Semester Fee\n";
    cout << "3. Tap Card\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\n==== Admin Menu ====\n";
    cout << "1. Create Route\n";
    cout << "2. Create Bus\n";
    cout << "3. Assign Student to Stop\n";
    cout << "4. Display registered Students\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void studentMenu(TransportationSystem &system) {
    int choice = 0;
    do {
        displayStudentMenu();
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) {
            string id, name;
            cout << "Enter Student ID: ";
            getline(cin, id);
            cout << "Enter Student Name: ";
            getline(cin, name);
            system.registerStudent(id, name);
        }
        else if (choice == 2) {
            string id;
            cout << "Enter Student ID for fee payment: ";
            getline(cin, id);
            system.paySemesterFee(id);
        }
        else if (choice == 3) {
            int busId;
            string id;
            cout << "Enter Bus ID: ";
            cin >> busId;
            cin.ignore();
            cout << "Enter Student ID: ";
            getline(cin, id);
            system.tapCard(busId, id);
        }
        else if (choice != 4) {
            cout << "Invalid option. Please try again." << endl;
        }
    } while(choice != 4);
}

void adminMenu(TransportationSystem &system) {
    int choice = 0;
    do {
        displayAdminMenu();
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) {
            string routeId;
            int numStops;
            cout << "Enter Route ID/Name: ";
            getline(cin, routeId);
            cout << "Enter number of stops: ";
            cin >> numStops;
            cin.ignore();
            if(numStops > 0) {
                string* stops = new string[numStops];
                for (int i = 0; i < numStops; i++) {
                    cout << "Enter name for Stop " << (i+1) << ": ";
                    getline(cin, stops[i]);
                }
                system.createRoute(routeId, stops, numStops);
                delete[] stops;
            }
        }
        else if (choice == 2) {
            int busId;
            string routeId;
            cout << "Enter Bus ID (number): ";
            cin >> busId;
            cin.ignore();
            cout << "Enter Route ID/Name to assign this bus: ";
            getline(cin, routeId);
            system.createBus(busId, routeId);
        }
        else if (choice == 3) {
            string stdId, stopName;
            cout << "Enter Student ID: ";
            getline(cin, stdId);
            cout << "Enter Stop Name (exactly as created in the route): ";
            getline(cin, stopName);
            system.assignStudentToStop(stdId, stopName);
        }
        else if (choice == 4) {
            system.displayRegisteredStudents();
        }
        else if (choice != 5) {
            cout << "Invalid option. Please try again." << endl;
        }
    } while(choice != 5);
}

int main(){
    cout << "\nName: Amna Ahsan\nID: 24K-0755\n\n";
    TransportationSystem system;
    int roleChoice = 0;

    //Register some students
    system.registerStudent("24K-0755", "Amna");
    system.registerStudent("24K-1013", "Aisha");
    system.paySemesterFee("24K-0755");
    const int numStops = 3;
    const string stops[numStops] = {"Stop1: Quidabad", "Stop2: Malir Halt", "Stop3: Shama"};
    system.createRoute("Malir", stops, numStops);
    system.createBus(39, "Malir"); 
    system.assignStudentToStop("24K-1013", "Stop1: Quidabad");
    system.assignStudentToStop("24K-0755", "Stop2: Malir Halt");
    system.tapCard(39, "24K-0755");

    do {
        displayMainMenu();
        cin >> roleChoice;
        cin.ignore(); 
        if(roleChoice == 1) {
            studentMenu(system);
        }
        else if(roleChoice == 2) {
            adminMenu(system);
        }
        else if(roleChoice == 3) {
            cout << "Exiting system. Goodbye!" << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    } while(roleChoice != 3);
    
    
    return 0;
}
