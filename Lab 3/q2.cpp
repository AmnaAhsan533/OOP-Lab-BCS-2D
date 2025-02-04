#include<iostream>
using namespace std;

class Date{
    public:
    int day;
    int month;
    int year;

    void displayDate(){
        cout<<month<<"/"<<day<<"/"<<year;
    }
};

int main(){
    Date DateTest;
    DateTest.day = 4;
    DateTest.month = 2;
    DateTest.year = 2025;
    DateTest.displayDate();
}