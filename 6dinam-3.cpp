#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int findElement(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i+1;  
        }
    }
    return -1; 
}

int main() {
    srand(time(0));
    int n;
    cout << "array size: ";
    cin >> n;
    if (n <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }


    int* arr = new int[n];
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;


    int Numb;
    cout << "What number find? ";
    cin >> Numb;
    int index = findElement(arr, n, Numb);

    if (index != -1) {
        cout << "Number " << Numb << " found at position " << index << endl;
    }
    else {
        cout << "Number " << Numb << " not found" << endl;
    }
    delete[] arr;
    arr = nullptr;

    return 0;
}