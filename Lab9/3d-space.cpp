/*
	Author: Talha Rahman
	Course: CSCI-136
	Instructor: Minh Nguyen
	Assignment: Lab 9E
*/
// This program has a point in 3D space
// and computes the distance from that point
// from the origin
// it can make the pointers on the heap and on the stack
// and has some other functions to check its position
// after being shifted
#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
    public:
        double x, y, z;
        Coord3D(double x, double y, double z) : x(x), y(y), z(z) {}
};

double length(Coord3D* p){
    double x = p->x;
    double y = p->y;
    double z = p->z;
    return sqrt(pow(x, 2) + pow(y,2) + pow(z, 2));
}

Coord3D* fartherFromOrigin(Coord3D* p1, Coord3D* p2){
    if (length(p1) > length(p2)){
        return p1;
    } else {
        return p2;
    }
}

void move(Coord3D* ppos, Coord3D* pvel, double dt){
    ppos->x += (pvel->x * dt);
    ppos->y += (pvel->y * dt);
    ppos->z += (pvel->z * dt);
}

Coord3D* createCoord3D(double x, double y, double z){
    return new Coord3D(x, y, z);
}

void deleteCoord3D(Coord3D* p){
    delete p;
}

int main(){
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}