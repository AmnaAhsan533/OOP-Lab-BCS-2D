#include<iostream>
#include<vector>
using namespace std;

struct Person{
    int id;
    string name;
};

void print(const vector<Person>& persons){
    for(const auto& p: persons){
        cout << "ID: " << p.id << ", Name: "<< p.name << endl;
    }
    cout << endl;
}

void sortByID(vector<Person>& persons){
    int n = persons.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(persons[j].id > persons[j+1].id){
                swap(persons[j], persons[j+1]);
            }
        }
    }
}

void sortByName(vector<Person>& persons){
    int n= persons.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(persons[j].name[0] > persons[j+1].name[0]){
                swap(persons[j], persons[j+1]);
            }
        }  
    }
}

int main(){
    int n;
    cout << "Enter no. of persons: ";
    cin>>n;
    vector<Person> persons(n);

    for(int i=0; i<n; i++){
        cout<<"Enter ID: ";
        cin >> persons[i].id;
        cin.ignore();
        cout<<"Enter name: ";
        getline(cin, persons[i].name);
    }

    sortByID(persons);
    cout << "\nSorted by ID:\n";
    print(persons);

    sortByName(persons);
    cout << "Sorted by first character of Name:\n";
    print(persons);

}