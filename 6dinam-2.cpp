#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size error" << endl;
        return 1;
    }

    int* arr = new int[n];


    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; 
    }

    cout << "Massiv: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {  
            cout << " ";
        }
    }
    cout << endl;


    delete[] arr; 
    arr = nullptr;

    return 0;
}