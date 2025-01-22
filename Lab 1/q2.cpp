#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int *ptr = arr;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += *(ptr + i);
    }
    cout<<"Sum: "<<sum;
    return 0;
}