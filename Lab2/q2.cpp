#include<iostream>
#include<cstdlib>
using namespace std;

void* add(void *arr_void_ptr){
    int* arr = (int*)arr_void_ptr;
    for(int i=0; i<5; i++){
        arr[i] += 2;
    }
    return (void*)arr;
}

int main(int argc, char *argv[]){
    int arr[5];
    if(argc < 6){
        cout << "Usage: " << argv[0] << " num1 num2 num3 num4 num5" << endl;
        return 1;
    }
    for(int i=0; i<5; i++){
        arr[i] = atoi(argv[i+1]);
    }
    void* ptr = (void*)arr;
    void* ret = add(ptr);
    int *result = (int*)ret;
    cout <<"Modified Array: ";
    for(int i=0; i<5; i++){
        cout<<result[i]<<" ";
    }
}
