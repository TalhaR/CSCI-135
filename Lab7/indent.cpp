/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7B
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
    string input, modified;
    int tabs;
    
    while (getline(cin, input)){
        modified = removeLeadingSpaces(input);
        tabs = countChar(modified, '{');
        
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