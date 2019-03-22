/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 7B
*/

// This program takes in lines of code
// from another program and unindents the 
// start of each line. Afterwards it will
// start indenting accordingly based on 
// how many curly braces exist
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string);
int countChar(string, char);
string getTabs(int&);

int main(){
    string input, modified;
    int count = 0;
    
    while (getline(cin, input)){
        modified = removeLeadingSpaces(input);
        if (countChar(modified, '}') > 0){
            count -= countChar(modified, '}');
            //count--;
        }
        cout << getTabs(count) << modified << "\n";
        count += countChar(modified, '{');
        
    }
}

string getTabs(int& count){
    string result;
    for (int i = 0; i < count; i++){
        result += "\t";
    }
    return result;
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