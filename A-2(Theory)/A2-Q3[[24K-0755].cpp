#include<iostream>
using namespace std;

class Vehicle{
protected:
    static int deliveries;
    double speed, capacity, energyEfficiency;

public:
int id;
Vehicle(int id, double spd, double cap, double eff) :
     id(id), speed(spd), capacity(cap), energyEfficiency(eff) {
   deliveries++;
}
    virtual ~Vehicle() { deliveries--; }
    virtual void calculateRoute() = 0;
    virtual void estimateDeliveryTime() = 0;
    virtual void move() = 0;
    static int getActiveDeliveries() { return deliveries; }
    friend bool operator==(const Vehicle& v1, const Vehicle& v2);
    friend bool compareEfficiency(const Vehicle& v1, const Vehicle& v2);
    friend const Vehicle& resolveConflict(const Vehicle& v1, const Vehicle& v2);

};

int Vehicle::deliveries = 0;
bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return v1.id == v2.id;
}
bool compareEfficiency(const Vehicle& v1, const Vehicle& v2) {
    return (v1.speed * v1.capacity / v1.energyEfficiency) > (v2.speed * v2.capacity / v2.energyEfficiency);
}
const Vehicle& resolveConflict(const Vehicle& v1, const Vehicle& v2) {
    cout << "Resolving AI conflict between " << v1.id << " and " << v2.id << "...\n";
    return compareEfficiency(v1, v2) ? v1 : v2;
}
class RamzanDrone: public Vehicle{
public:
    RamzanDrone(int id) :  Vehicle(id, 100.0, 10.0, 5.0) {}
    void calculateRoute() override { cout << "Drone calculating aerial route...\n"; }
    void estimateDeliveryTime() override { cout << "Drone estimating high-speed delivery time...\n"; }
    void move() override { cout << "Drone moving swiftly to deliver Iftar meal.\n"; }
};

class RamzanTimeShip: public Vehicle{
public:
    RamzanTimeShip(int id) : Vehicle(id, 80.0, 20.0, 7.0) {}
    void calculateRoute() override { cout << "TimeShip verifying historical consistency...\n"; }
    void estimateDeliveryTime() override { cout << "TimeShip estimating delivery timeline across time periods...\n"; }
    void move() override { cout << "TimeShip traveling through time for accurate delivery.\n"; }
};

class RamzanHyperPod: public Vehicle{
public: 
    RamzanHyperPod(int id) :Vehicle(id, 120.0, 50.0, 10.0) {}
    void calculateRoute() override { cout << "HyperPod navigating underground tunnels...\n"; }
    void estimateDeliveryTime() override { cout << "HyperPod estimating bulk transport efficiency...\n"; }
    void move() override { cout << "HyperPod racing through tunnels for fast bulk delivery.\n"; }
};
class ControlPanel {
public:
    void command(string action, int packageID) {
        cout << "Executing: " << action << " for package " << packageID << "\n";
    }
    void command(string action, int packageID, string urgencyLevel) {
        cout << "Executing: " << action << " for package " <<
         packageID << " with urgency: " << urgencyLevel << "\n";
    }
};
int main() {
    cout<<"Amna Ahsan\nID: 24K-0755\n";
    RamzanDrone drone(1001);
    RamzanTimeShip timeShip(1002);
    RamzanHyperPod hyperPod(1003);
    cout<<endl;
    ControlPanel panel;
    panel.command("Deliver", 101);
    panel.command("Deliver", 102, "Urgent");
    cout<<endl;
    drone.calculateRoute();
    drone.estimateDeliveryTime();
    drone.move();
    cout<<endl;
    timeShip.calculateRoute();
    timeShip.estimateDeliveryTime();
    timeShip.move();
    cout<<endl;
    hyperPod.calculateRoute();
    hyperPod.estimateDeliveryTime();
    hyperPod.move();
    cout<<endl;
    cout << "Active Deliveries: " << Vehicle::getActiveDeliveries() << "\n\n";
    cout << "Comparing Drone and HyperPod Efficiency: " << 
    (compareEfficiency(drone, hyperPod) ? "Drone is more efficient" : "HyperPod is more efficient") << "\n\n";
    const Vehicle& bestVehicle = resolveConflict(drone, hyperPod);
    cout << "Best vehicle chosen: " << bestVehicle.id << "\n";
    return 0;
}
