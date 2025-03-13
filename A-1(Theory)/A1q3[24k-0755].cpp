#include <iostream>
#include <string>
using namespace std;

const int LEARNER = 0;
const int INTERMEDIATE = 1;
const int FULL = 2;
string licenseToString(int license) {
    switch (license) {
        case LEARNER: return "Learner";
        case INTERMEDIATE: return "Intermediate";
        case FULL: return "Full";
        default: return "Unknown";
    }
}
class User {
public:
    string name;
    int age;
    int license_type;
    string contact;
    int user_id;
    User(string n, int a, int license, string cont, int id)
        : name(n), age(a), license_type(license), contact(cont), user_id(id) {}
    void updateDetails(string new_name, int new_age, int new_license, string new_contact){
        name = new_name;
        age = new_age;
        license_type = new_license;
        contact = new_contact;
    }
    void display() {
        cout << "\nUser Details:\n";
        cout << "Name: " << name << "\nAge: " << age
             << "\nLicense Type: " << licenseToString(license_type)
             << "\nContact: " << contact << "\nUser ID: " << user_id << endl;
    }
};
class Vehicle {
public:
    string model;
    double rental_price;
    int eligibility;
    Vehicle(string m, double rent, int eligible)
        : model(m), rental_price(rent), eligibility(eligible) {}
    void display() const {
        cout << "Model: " << model
             << " | Price per day: $" << rental_price
             << " | Required License: " << licenseToString(eligibility) << endl;
    }
};
bool isEligible(const User &user, const Vehicle &vehicle) {
    return user.license_type >= vehicle.eligibility;
}

int main() {
    cout << "\nName: Amna Ahsan\nID: 24K-0755\n\n";
    cout << "--- Vehicle Rental System ---\n";
    string name, contact;
    int id, age, li_choice;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter User ID: ";
    cin >> id;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Select License Type (0 = Learner, 1 = Intermediate, 2 = Full): ";
    cin >> li_choice;
    cout << "Enter Contact Number: ";
    cin >> contact;

    User currentUser(name, age, li_choice, contact, id);

    int numVehicles = 3;
    Vehicle **vehicles = new Vehicle *[numVehicles];

    vehicles[0] = new Vehicle("Toyota Corolla", 100.0, LEARNER);    // Learners and above
    vehicles[1] = new Vehicle("BMW 3 Series", 200.0, INTERMEDIATE); // Intermediate and Full
    vehicles[2] = new Vehicle("Honda City", 300.0, FULL);           // Only for Full license

    cout << "\n--- Available Vehicles ---\n";
    for (int i = 0; i < numVehicles; i++) {
        cout << i + 1 << ". ";
        vehicles[i]->display();
    }

    int choice;
    cout << "\nEnter the number of the vehicle you want to rent: ";
    cin >> choice;

    if (choice < 1 || choice > numVehicles) {
        cout << "Invalid Choice!\n";
    } else {
        Vehicle *selected = vehicles[choice - 1];
        if (isEligible(currentUser, *selected)) {
            cout << "\n You are eligible to rent the " << selected->model << ".\n";
            cout << "Rental Details:\n";
            cout << " - Model: " << selected->model << "\n";
            cout << " - Price per day: $" << selected->rental_price << "\n";
        } else {
            cout << "\nYou are NOT eligible to rent the " << selected->model
                 << " based on your license type (" << licenseToString(currentUser.license_type) << ").\n";
        }
    }
    char updateChoice;
    cout << "\nDo you want to update your details? (y/n): ";
    cin >> updateChoice;
    if (updateChoice == 'y' || updateChoice == 'Y') {
        cout << "\n--- Update Details ---\n";
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter New Age: ";
        cin >> age;
        cout << "Select New License Type (0 = Learner, 1 = Intermediate, 2 = Full): ";
        cin >> li_choice;
        cout << "Enter New Contact Number: ";
        cin >> contact;

        currentUser.updateDetails(name, age, li_choice, contact);
        cout << "\n Details Updated Successfully!\n";
        currentUser.display();
    }

    for (int i = 0; i < numVehicles; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;

    return 0;
}
