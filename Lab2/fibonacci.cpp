#include <iostream>
using namespace std;

/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 2D
*/

// This program uses an array of ints to compute and print all the 
// Fibonacci numbers from F(0) to F(59)

int main() {
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 0; i < 60; i++){
        if (i > 1){
            fib[i] = fib[i-1] + fib[i-2];
        }
        cout << fib[i] << "\n";
    }
    // fib[47] and onwards, the numbers are larger
    // than the amount of memory allocated for the
    // integer value, which is like 2^32. But 
    // we're not using an unsigned int, so the 
    // largest number is half that, so about
    // 2.1 billion. Once we try to compute a larger
    // number than 2.1 billion and put it into a 
    // regular int it doesn't go smoothly
}