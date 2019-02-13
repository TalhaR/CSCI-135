/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 3B
*/

// This program prints out the minimum and maximum storage in 
// the East Basin in 2018
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr << "File cannot be opened for reading.\n";
        exit(1); // exit if failed to open file
    }

    string junk; // used to store & ignore header of file
    getline(fin, junk);

    string date;
    double eastSt, eastEl, westSt, westEl;
    double lowest = INT_MAX;
    double highest = INT_MIN;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns 

        if (eastSt < lowest){
            lowest = eastSt;
        }
        if (eastSt > highest){
            highest = eastSt;
        }
    }

    cout << "Minimum storage in East basin: " << lowest << " billion gallons\n";
    cout << "Maximum storage in East basin: " << highest << " billion gallons\n";

    fin.close();
}