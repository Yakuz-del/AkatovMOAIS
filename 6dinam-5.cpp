#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countEvenNumbers(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {  
            count++;
        }
    }
    return count;
}


int* filterEven(int* arr, int size, int& newSize) {
    newSize = countEvenNumbers(arr, size);
    int* evenArr = new int[newSize];

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[index] = arr[i];
            index++;
        }
    }

    return evenArr;  
}


void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void printArray(int* arr, int size, const char* message = "") {
    if (message[0] != '\0') {
        cout << message;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) cout << " ";
    }
    cout << endl;
}

int main() {

    srand(time(0));
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20 + 1;  
    }


    printArray(arr, n, "Original array: ");

    int evenSize;
    int* evenArr = filterEven(arr, n, evenSize);

    if (evenSize == 0) {
        cout << "No even numbers found!" << endl;
        delete[] arr;
        return 0;
    }

    printArray(evenArr, evenSize, "Even numbers: ");


    bubbleSort(evenArr, evenSize);  


    printArray(evenArr, evenSize, "After sorting: ");

    delete[] arr;
    delete[] evenArr;

    return 0;
}