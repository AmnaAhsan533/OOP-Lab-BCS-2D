#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    float w;
    cout<<"Enter weight in kg: ";
    cin>>w;
    cout<<fixed<<setprecision(2)<<w<<" kg"<<endl;
    w = w * 2.2;
    cout<<fixed<<setprecision(2)<<w<<" pounds";

    return 0;
}