#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int cap = 3;  
    int size = 0;     
    int* arr = new int[cap];

    int number;
    while (true) {
        cout << "Enter number (0 to exit): ";
        cin >> number;
        if (number == 0) {
            break;
        }

        if (size == cap) {
          
            int newCap = cap + 2;
            int* newArr = new int[newCap];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }


            delete[] arr;

        
            arr = newArr;
            cap = newCap;

            cout << "Expanding to " << cap << " elements" << endl;
        }


        arr[size] = number;
        size++;
    }

 
  
    printArray(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}