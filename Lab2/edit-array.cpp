/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 2C
*/

// This program creates an array of 10 integers
// and lets the user edit any of the elements in an array
#include <iostream>
using namespace std;


int main() {
    int myData[10];
    int index;

    for (int i = 0; i < 10; i++){
        myData[i] = 1;
    }
    
    while (true) {
        for (int i = 0; i < 10; i++){
            cout << myData[i] << " ";
        }

        cout << "\nInput index: ";
        cin >> index;
        if ((index < 0) or (index >= 10)) {
            cout << "\nIndex out of range. Exiting";
            break; // ends program if they input an out-of-range index
        }
        cout << "\nInput value: ";
        int value;
        cin >> value;
        myData[index] = value;
    }
}