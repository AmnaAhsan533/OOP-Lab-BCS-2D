#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    // if(argc <2){
    //     cout<<"Usage: "<<argv[0]<<"<list of numbers>"<<endl;
    //     return 1;
    // }
    int n;
    n = argc -1;
    int arr[n];
    int *ptr = arr;
    int sum =0;
    for(int i=0; i<n; i++){
        arr[i] = atoi(argv[1+i]);
    }
    for(int i=0; i<n; i++){
        sum += *(ptr + i);
    }
    cout << "Sum: " << sum <<endl;

}