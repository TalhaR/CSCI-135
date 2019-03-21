/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7A
*/

// This program takes in lines of code
// from another program and unindents the 
// start of each line
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string);
int countChar(string, char);

int main(){
    string input;
    while (getline(cin, input)){
        cout << removeLeadingSpaces(input) << "\n";
    }
}

int countChar(string line, char c){
    int count = 0;
    for (auto& x : line){
        if (x == c) count++;
    }
    return count;
}

string removeLeadingSpaces(string line){
    string result;
    bool canStart = false;

    for (auto& x : line){
        if (!isspace(x)) canStart = true;

        if (canStart){
            result += x;
        }
    }
    return result;
}