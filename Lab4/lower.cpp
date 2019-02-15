/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4D
*/

// This program asks the user for a side length
// then prints the bottom left half of a square
#include <iostream>

using namespace std;

int main(){
    int length;

    cout << "Input side length: ";
    cin >> length;

    cout << "\nShape:\n";

    for (int i = 0; i < length; i++){
        for (int j = 0; j < i+1; j++){
            cout << "*";
        }
        cout << "\n";
    }
}