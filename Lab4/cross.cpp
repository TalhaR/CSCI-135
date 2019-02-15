/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4C
*/

// This program asks the user for a size then
// prints a diagonal cross of that dimension
#include <iostream>

using namespace std;

int main(){
    int size;

    cout << "Input size: ";
    cin >> size;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if ((j == 0 + i) or (j == size - 1 - i)){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}