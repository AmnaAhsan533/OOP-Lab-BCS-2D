#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct Employee{
    int id, years;
    string name, desig;

    Employee(int id, const string& name, const string& desig, int years)
        : id(id), name(name), desig(desig), years(years) {}

    string to_string() const {
        return std::to_string(id) + "," + name + "," + desig + "," + std::to_string(years);
    }
};

void writeData(const string& filename){
    ofstream out(filename);
    vector<Employee> employees = {
        {1, "Amna", "Manager", 3},
        {2, "Tania", "Manager", 5},
        {3, "Isbah", "developer", 1},
        {4, "Aisha", "Manager", 1}
    };

    for (const auto& emp : employees)
        out << emp.to_string() << endl;

    out.close();
}

vector<Employee> queryManagers(const string& filename){
    ifstream in(filename);
    string line;
    vector<Employee> result;

    while(getline(in, line)){
        stringstream ss(line);
        string idStr, name, desig, yearsStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, desig, ',');
        getline(ss, yearsStr, ',');

        int id = stoi(idStr);
        int years = stoi(yearsStr);

        if (desig == "Manager" && years >= 2)
            result.push_back({id, name, desig, years});
    }
    in.close();
    return result;
}

void deleteQuery(const string& filename, const vector<Employee>& filtered){
    ofstream out(filename, ios::trunc);
    for(const auto& emp : filtered)
        out <<emp.to_string() <<endl;
    out.close();
}

void rewriteQuery(const string& filename, const vector<Employee>& data){
    ofstream out(filename, ios::trunc);
    for (auto emp : data) {
        emp.id += 2;
        emp.years += 1;
        out << emp.to_string() << endl;
    }
    out.close();
}
int main() {
    string filename = "employees.txt";

    writeData(filename);

    cout << "\nQuery A: Manager with >= 2 years\n";
    auto result = queryManagers(filename);
    for (auto& emp : result)
        cout << emp.to_string() << endl;

    cout << "\nQuery B: Overwriting with only filtered data\n";
    deleteQuery(filename, result);

    cout << "\nQuery C: Writing incremented data\n";
    rewriteQuery(filename, result);

    return 0;
}
