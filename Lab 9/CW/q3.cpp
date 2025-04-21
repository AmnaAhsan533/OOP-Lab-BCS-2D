#include<iostream>
using namespace std;
class PatientRecord {
private:
    string name;
    string patientID;
    string dateOfBirth;

    string medicalHistory;
    string currentTreatment;
    string billingInfo;

public:
    PatientRecord(string n, string id, string dob)
        : name(n), patientID(id), dateOfBirth(dob) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + patientID + ", DOB: " + dateOfBirth;
    }
    string getMedicalData() const {
        return "History: " + medicalHistory + ", Current: " + currentTreatment;
    }

private:
    void updateMedicalHistory(const string& history) {
        medicalHistory = history;
    }

    void addBillingDetails(const string& billing) {
        billingInfo = billing;
    }

    string getBillingInfo() const {
        return billingInfo;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void addMedicalHistory(PatientRecord& record, const string& notes) {
        record.updateMedicalHistory(notes);
    }

    void viewMedicalInfo(const PatientRecord& record) {
        cout << "Doctor Access: " << record.getMedicalData() << "\n";
    }
};

class Billing {
public:
    void addBillingInfo(PatientRecord& record, const string& billing) {
        record.addBillingDetails(billing);
    }

    void viewBillingInfo(const PatientRecord& record) {
        cout << "Billing Access: " << record.getBillingInfo() << "\n";
    }
};

class Receptionist {
    public:
        void tryToAccessEverything(PatientRecord& record) {
            cout << "Receptionist: Public Info: " << record.getPublicData() << "\n";
            cout << "Receptionist: Medical Info: " << record.getMedicalData(); 
            // record.updateMedicalHistory("Oops"); //Not allowed
        }
};
    

int main() {
    PatientRecord patient("Amna", "P123", "2006-05-9");

    Doctor doc;
    Billing billingStaff;
    Receptionist frontDesk;

    frontDesk.tryToAccessEverything(patient); 

    doc.addMedicalHistory(patient, "Diagnosed with hypertension.");
    doc.viewMedicalInfo(patient); 

    billingStaff.addBillingInfo(patient, "Bill: $500");
    billingStaff.viewBillingInfo(patient); 

    //patient.updateMedicalHistory("Hack"); //Not Allowed
}


