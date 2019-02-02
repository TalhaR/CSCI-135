#include <iostream>
using namespace std;

/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 2B
*/

// The program will ask the user for two integers 
// and will print all the integers between that range (L <= i < U)
// seperated by spaces

int main() {
    int L, U;

    cout << "Please enter L: ";
    cin >> L;
    cout << "\nPlease enter U: ";
    cin >> U;

    for (int i = L; i < U; i++){
        cout << i << " ";
    }
}