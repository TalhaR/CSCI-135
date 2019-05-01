/*
Author: Talha Rahman
Course: CSCI-135
Instructor: Maryash
Assignment: Project 3
*/

// This program is used to control the movement of 
// the dwarves, such as getting them to walk around
// in addition it can also control which trees they cut
// and a few other stuff.
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"
using namespace std;

struct Location {
  int r = 5;
  int c = 6;
  void incrementC(){
    c++;
  }
  void incrementR(){
    r++;
  }
};

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;
bool STUCK = false;
bool BUILDING = false;
Location BASE; 

bool isNextToATree(Dwarf&, int&, int&, Dir&);
void lookForNextTree(Dwarf&, int&, int&, int);
void checkForSpace(Dwarf&, int&, int&);
bool isPossible(int&, int&);



/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!\n"; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

/* onAction: 
A procedure called each time an idle dwarf is choosing 
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();
  Dir d;

  // Check if there is a tree adjacent to dwarf
  if (isNextToATree(dwarf, r, c, d)) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop\n";
    dwarf.start_chop(d);
    STUCK = false;
    return;
  }

  if (dwarf.lumber() == 0) BUILDING = false;

  ///cygdrive/c/Users/talha/documents/Git/csci-135/project3/dwarves2

  if (BUILDING && dwarf.look(BASE.r, BASE.c) == FENCE){
    log << "Building a fence\n";
    dwarf.start_build(WEST);
    BASE.incrementC();
  } else {
    log << "Walk to " << BASE.r << " " << BASE.c << "\n";
    dwarf.start_walk(BASE.r, BASE.c);
    return;
  }

  if (dwarf.lumber() > 50 && dwarf.look(BASE.r, BASE.c) == EMPTY){
    log << "Walk to " << BASE.r << " " << BASE.c << "\n";
    dwarf.start_walk(BASE.r, BASE.c);
    
    return;
  }


  if (STUCK){
  // Otherwise, move to a random location 
    int rr = rand() % ROWS;
    int cc = rand() % COLS;

    log << "Walk to " << rr << " " << cc << "\n";
    dwarf.start_walk(rr, cc);
    return;
  } else {
    lookForNextTree(dwarf, r, c, 1);

    if(isPossible(r, c)){
      log << "Walk to " << r << " " << c << "\n";
      dwarf.start_walk(r, c);
      STUCK = true;
    }
    return;
  }
}
// will find an empty space near a tile
void checkForSpace(Dwarf& dwarf, int &r, int &c){
  if (dwarf.look(r, c+1) == EMPTY) { // EAST
    c++;
    return;
  }
  if (dwarf.look(r, c-1) == EMPTY) { // WEST
    c--;
    return;
  }
  if (dwarf.look(r-1, c) == EMPTY ){ // NORTH
    r--;
    return;
  }
  if (dwarf.look(r+1, c) == EMPTY) { // SOUTH
    r++;
    return;
  }
  r = rand() % ROWS; 
  c = rand() % COLS;
}

void lookForNextTree(Dwarf &dwarf, int &r, int &c, int count){
  if (dwarf.look(r, c+count) == PINE_TREE || dwarf.look(r, c+count) == APPLE_TREE) {
    c += --count;
    return;
  }
  if (dwarf.look(r, c-count) == PINE_TREE || dwarf.look(r, c-count) == APPLE_TREE) {
    c -= --count;
    return;
  }
  if (dwarf.look(r-count, c) == PINE_TREE || dwarf.look(r-count, c) == APPLE_TREE){
    r -= --count;
    return;
  }
  if (dwarf.look(r+count, c) == PINE_TREE || dwarf.look(r+count, c) == APPLE_TREE) {
    r += --count;
    return;
  }
  // diagonals
  if (dwarf.look(r+count, c+count) == PINE_TREE || dwarf.look(r+count, c+count) == APPLE_TREE) {
    r += count; c += count;
    checkForSpace(dwarf, r, c);
    return;
  }
  if (dwarf.look(r-count, c-count) == PINE_TREE || dwarf.look(r-count, c-count) == APPLE_TREE) {
    r -= count; c -= count;
    checkForSpace(dwarf, r, c);
    return;
  }
  if (dwarf.look(r+count, c-count) == PINE_TREE || dwarf.look(r+count, c-count) == APPLE_TREE) {
    r += count; c -= count;
    checkForSpace(dwarf, r, c);
    return;
  }
  if (dwarf.look(r-count, c+count) == PINE_TREE || dwarf.look(r-count, c+count) == APPLE_TREE) {
    r -= count; c += count;
    checkForSpace(dwarf, r, c);
    return;
  }
  // recursively calls to check for tiles that are farther out
  lookForNextTree(dwarf, r, c, ++count);
}

// this function will check if the dwarf is next to a tree
// it can be either pine or apple, doesn't matter
// and then it will return not only a boolean value of true
// but will modify the variable d to be the direction
// that the tree was found in so I can use it later
// when choping so I don't have to check what direction
// the tree is in again
bool isNextToATree(Dwarf &dwarf, int &r, int &c, Dir &d){
  if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE) {
    d = EAST;
    return true;
  }
  if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE) {
    d = WEST;
    return true;
  }
  if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE){
    d = NORTH;
    return true;
  }
  if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE) {
    d = SOUTH;
    return true;
  }
  return false;
}

bool isPossible(int &r, int &c){
  if ((r < 0) || (r > ROWS)) return false;
  if ((c < 0) || (c > COLS)) return false;
  return true;
}

