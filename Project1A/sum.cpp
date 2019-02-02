/*
Author: Talha Rahman
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1A - Task A
*/

// This program adds up numbers from a file
// requires linux command of "./sum < numbers.txt"
#include <iostream>

using namespace std;

int main(){
	int sum = 0;
	int input;
	
	while (cin >> input){
		sum += input;
	}
	
	cout << sum << endl;	
}
