#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    string f_name, l_name;
    double scores[5];
    cin>>f_name>>l_name;
    for(int i=0; i<5; i++){
        cin>>scores[i];
    }
    double sum = 0, avg = 0;
    cout<<"Student Name: "<<f_name<<" "<<l_name<<endl;
    cout<<"Test scores: ";
    for(int i=0; i<5; i++){
        sum += scores[i];
        cout<<fixed<<setprecision(2)<<scores[i]<<" ";
    }
    cout<<endl;
    avg = sum / 5;
    cout<<"Average test score: "<<fixed<<setprecision(2)<<avg;

    return 0;
}