#include<iostream>
using namespace std;

int add(int *arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = arr[i] + 2;
    }
    return (void*)arr;
}

int main(){
    int arr;
}