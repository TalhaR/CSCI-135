/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4A
*/

// This program asks the user for a width and height
// and then prints a solid rectangular box of the 
// of the requested size using asterisks 
#include <iostream>

using namespace std;

int main(){
    int width, height;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "\nShape:\n";

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << "*";
        }
        cout << "\n";
    } 
}