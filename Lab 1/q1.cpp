#include<iostream>
using namespace std;
int main(int argc, char *argv[]){
    float arr[20];
    for(int i=0; i<20; i++){
        cin>>arr[i];
    }
    float max =0.0, s_max = 0.0;
    float *ptr = arr;
    for(int i=0; i<20; i++){
        if(*(ptr + i) > max){
            s_max = max;
            max = *(ptr + i);
        } else if(*(ptr + i) > s_max && *(ptr + i) != max){
            s_max = *(ptr + i);
        }
    }
    cout<<"Second highest: "<<s_max;
    return 0;
}