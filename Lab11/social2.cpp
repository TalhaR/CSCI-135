#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"
using namespace std;

int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                    "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
