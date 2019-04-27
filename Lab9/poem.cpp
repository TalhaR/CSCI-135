/*
	Author: Talha Rahman
	Course: CSCI-136
	Instructor: Minh Nguyen
	Assignment: Lab 9D
*/

// this program creates a string pointer in a method
// and that pointer is created on the heap and is
// returned to the main method 
#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        
        // assume that the poem p is not needed at this point
        delete p;
    }
}