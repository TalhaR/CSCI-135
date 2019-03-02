/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 5G
*/

// This program asks the user for two
// integers. This makes an interval.
// the program then checks all the
// numbers in that interval and then
// returns the number of primes 
// using 
// does anyone read these comments?
// XD
#include<iostream>
using namespace std;

bool isDivisibleBy(int n, int d){
    if (d == 0){
        return false;
    } else if (n % d == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n){
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int i = 1;
    while(true){
        if (isPrime(n+i)){
            return n+i;
        } 
        i++;
    }
    return n;
}

int countPrimes(int a, int b){
    int count = 0;
    while (a != b+1){
        if (isPrime(a)){
            count++;
        }
        a++;
    }
    return count;
}

bool isTwinPrime(int n){
    if (!isPrime(n)) return false;

    if(isPrime(n-2) or isPrime(n+2)){
        return true;
    }
    return false;
}

int nextTwinPrime(int n){
    int i = 1;
    while(true){
        if (isTwinPrime(n+i)){
            return n+i;
        } 
        i++;
    }
    return n;
}

int largestTwinPrime(int a, int b){
    for(int i = b; i >= a; i--){
        if (isTwinPrime(i)){
            return i;
        }
    }

    return -1;
}

int main(){
    int num1, num2;
    
    cout << "Please input two integer: ";
    cin >> num1 >> num2;

    cout << "The largest twin prime number in that range is " << largestTwinPrime(num1, num2);
}