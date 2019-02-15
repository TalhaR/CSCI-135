/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4G
*/

// This program asks the user for a width
// and a height. Then creates a checkerboard of 
// 3 x 3 squares for each tile
#include <iostream>
#include <string>

using namespace std;

int main(){
    int width, height;
    string board;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "\nShape:\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {      
            if ((j / 3) % 2 == ((i / 3) % 2)) {
	            board += "*";
            } else {
	            board += " ";
            }
        }
        board += "\n";
    }
    cout << board;
}