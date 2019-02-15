/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 4F
*/

// This program asks the user for a width
// and a height. Then creates an upside-down
// trapezoid of given width and height
#include <iostream>

using namespace std;

int main(){
    int width, height;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    if (height > (width + 1)/2){
        cout << "Impossible shape!";
        exit(1);
    }

    cout << "\nShape:\n";

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width - i; j++){
            if (j < i){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}