#include <iostream>
using namespace std;

/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 2A 
*/

// The program will ask the user for an input between 0 and 100
// If the number is out of that range. I will force them to re-enter
// Once it's done correctly, I print n squared.

int main() {
    int input;
    do {
        cout << "Please enter an integer (0 < n < 100): ";
        cin >> input;
    } while ((input >= 100) or (input <= 0));

    cout << "Number squared is " << input * input;
}