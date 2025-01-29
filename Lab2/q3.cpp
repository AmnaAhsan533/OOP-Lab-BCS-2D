#include <iostream>
#include <cstring> 
using namespace std;

void resize(int*& arr, int& cap, int new_cap) {
    int* newArr = new int[new_cap];
    memcpy(newArr, arr, sizeof(int) * cap); 
    delete[] arr;
    arr = newArr;
    cap = new_cap; 
}

int main() {
    int n = 0, value, cap = 5;
    int* arr = new int[cap]; 
    
    cout << "Enter elements (-1 to stop)" << endl;
    
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }

        if (n == cap) {
            resize(arr, cap, 2 * cap); 
        }

        arr[n++] = value; 
    }
    if (n < cap) {
        resize(arr, cap, n);
    }

    cout << "Final array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }

    delete[] arr; 
    return 0;
}
