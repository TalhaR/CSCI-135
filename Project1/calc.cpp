/*
Author: Talha Rahman
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1A - Task B
*/

// This program reads from a text file that should 
// contain numbers that are either added or subtracted
// and prints out the total of that equation
// requires linux command "./calc < formula.txt"
#include <iostream>
#include <string>
using namespace std;

int main() {
    char input; // initial input
    int num; // integer version of the char(s) input
    int total = 0;
    int nextNum = 0; 
    bool add = true;
    
    while (cin >> input) {                                                                                                             
        if (input == '+') { 
            add ? (total += nextNum) : (total -= nextNum);
            add = true;
            nextNum = 0;      
        } else if (input == '-') {
            add ? (total += nextNum) : (total -= nextNum);
            add = false;
            nextNum = 0;      
        } else {
            nextNum *= 10; // need to multiply by 10 to shift number from ones to tens place, or tens to hundreds
            num = input - 48; // on the ascii table numbers start at 48. So subtract by 48 to convert to digits
            nextNum += num;      
        } 
    }
    add ? (total += nextNum) : (total -= nextNum);

    cout << total << "\n";
}
