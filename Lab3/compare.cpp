/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 3C
*/

// This program asks the user for two dates (beginning and ending of interval)
// It then prints out which basin had the higher elevation during that interval
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main(){
    
    string startingDate;
    string endingDate;

    cout << "Enter starting date: ";
    cin >> startingDate; 
    cout << "Enter ending date: ";
    cin >> endingDate; 

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

        if ((date >= startingDate) && (date <= endingDate)){
            if (eastEl > westEl){
                cout << date << " East\n";
            } else if (eastEl < westEl){
                cout << date << " West\n";
            } else {
                cout << date << " Equal\n";
            }
        }
    }

    fin.close();
}