/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 3A
*/

// This program asks the user to input a string representing 
// a date (in MM/DD/YYYY format), and prints out the East basin storage on that day
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main(){
    
    string userInput;

    cout << "Enter date: ";
    cin >> userInput; 

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr << "File cannot be opened for reading.\n";
        exit(1); // exit if failed to open file
    }

    string junk; // used to store & ignore header of file
    getline(fin, junk);

    string date;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns 

        //cout << date << " " << eastSt << "\n";
        if (userInput == date){
            cout << "East basin storage: " << eastSt << " billion gallons\n";
        }
    }

    fin.close();
}