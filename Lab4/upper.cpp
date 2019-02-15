/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4E
*/

// This program asks the user for a side length
// then prints out the top-right half of a square
#include <iostream>

using namespace std;

int main(){
    int length;

    cout << "Input side length: ";
    cin >> length;

    cout << "\nShape:\n";

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            if (j < i){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}