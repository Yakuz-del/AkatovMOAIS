#include <iostream>
using namespace std;

int main() {


    int a = 10;
    int* ptr = &a;
    cout << "a = " << a << endl;
    cout << "Address: " << &a << endl;
    cout << "ptr address: " << ptr << endl;
    cout << "ptrvalue: " << *ptr << endl;

    *ptr = 20;

    cout << "a = " << a << endl;
    cout << "ptr value: " << *ptr << endl;



    
    int* dynamicPtr = new int;

    *dynamicPtr = 42;
  
    cout << "dynamicPtr address: " << dynamicPtr << endl;
    cout << "At this address number: " << *dynamicPtr << endl;
    cout << "Address " << &dynamicPtr << endl;

    delete dynamicPtr;

    return 0;
}