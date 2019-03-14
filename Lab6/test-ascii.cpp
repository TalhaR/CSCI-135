/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6A
*/

// This program asks the user for a string
// then prints out all the characters in that string
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s;
    cout << "Input: ";
    getline(cin, s);

    for (auto& x : s){
        cout << x << " " << (int)x << "\n";
    }
}

