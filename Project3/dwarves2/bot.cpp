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

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;
bool stuck = false;
bool firstTime = true;
static bool building = false;

bool isNextToTree(Dwarf&, int&, int&, Dir&);
bool isNextToFence(Dwarf&, int&, int&, Dir&);
bool lookForNextFence(Dwarf&, int&, int&, int, Dir&);
bool lookForNextTree(Dwarf&, int&, int&, int);
bool outofBounds(Dwarf&, int&, int&);
Dir checkForSpace(Dwarf&, int&, int&, int);
void goToRandomPosition(Dwarf&, ostream&);
//cygdrive/c/Users/talha/documents/Git/csci-135/project3/dwarves2

/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, ostream &log) {
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
  if (isNextToTree(dwarf, r, c, d)) {
    // If there is a pine tree, chop it
    log << "Dwarf " << dwarf.name() << " - Chopping at " << r << " " << c << " \n";
    dwarf.start_chop(d);
    stuck = false;
    return;
  }

  if(isNextToFence(dwarf, r, c, d)){
    if(outofBounds(dwarf, r, c)) {
      goToRandomPosition(dwarf, log);
      return;
    }
    log << "Dwarf " << dwarf.name() << " - Building fence at " << r << " " << c << "\n";
    dwarf.start_build(d);
    stuck = false;
    return;
  }
  
  // Moves dwarf to next empty tile if repeating actions
  if (stuck){
    goToRandomPosition(dwarf, log);
    return;
  } 

  if (building){
    if (lookForNextFence(dwarf, r, c, 1, d)) {

      log << "Dwarf " << dwarf.name() << " - Fence found. Walking to " << r << " " << c << "\n";
      dwarf.start_walk(r, c);
      return;
    } else {
      checkForSpace(dwarf, r, c, 1);
      log << "Dwarf " << dwarf.name() << " - Can't find fence. Walking to " << r << " " << c << "\n";
      dwarf.start_walk(r, c);
      return;
    }
  }

  if(dwarf.lumber() >= 300 && firstTime){
    dwarf.start_build(checkForSpace(dwarf, r, c, 1));
    log << "Dwarf " << dwarf.name() << " - Building fence at " << r << " " << c << "\n";
    firstTime = false;
    building = true;
    return;
  }

  if(lookForNextTree(dwarf, r, c, 1) && !building){ // go next to tree
    log << "Dwarf " << dwarf.name() << " - Tree found. Walking to " << r << " " << c << "\n";
    dwarf.start_walk(r, c);
    stuck = false;
  } else if (!building){ // go to next empty tile
    checkForSpace(dwarf, r, c, 1);
    log << "Dwarf " << dwarf.name() << " - Looking for tree. Walking to " << r << " " << c << "\n";
    dwarf.start_walk(r, c);
    stuck = false;
  }
}

bool outofBounds(Dwarf& dwarf, int& r, int& c){
  if (r < 0 || r > ROWS) return true;
  if (c < 0 || c > COLS) return true;
  return false;
}
// will find an empty space near a tile
Dir checkForSpace(Dwarf& dwarf, int &r, int &c, int count){
  if (dwarf.look(r-count, c) == EMPTY ){ // NORTH
    r--;
    return NORTH;
  }
  if (dwarf.look(r, c+count) == EMPTY) { // EAST
    c++;
    return EAST;
  }
  if (dwarf.look(r+count, c) == EMPTY) { // SOUTH
    r++;
    return SOUTH;
  }
  if (dwarf.look(r, c-count) == EMPTY) { // WEST
    c--;
    return WEST;
  }
  r = rand() % ROWS; 
  c = rand() % COLS;
}

bool lookForNextTree(Dwarf &dwarf, int &r, int &c, int count){
  if (dwarf.look(r, c+count) == PINE_TREE || dwarf.look(r, c+count) == APPLE_TREE) {
    c += --count;
    return true;
  }
  if (dwarf.look(r, c-count) == PINE_TREE || dwarf.look(r, c-count) == APPLE_TREE) {
    c -= --count;
    return true;
  }
  if (dwarf.look(r-count, c) == PINE_TREE || dwarf.look(r-count, c) == APPLE_TREE){
    r -= --count;
    return true;
  }
  if (dwarf.look(r+count, c) == PINE_TREE || dwarf.look(r+count, c) == APPLE_TREE) {
    r += --count;
    return true;
  }
  // diagonals
  if (dwarf.look(r+count, c+count) == PINE_TREE || dwarf.look(r+count, c+count) == APPLE_TREE) {
    r += count; c += count;
    checkForSpace(dwarf, r, c, 1);
    return true;
  }
  if (dwarf.look(r-count, c-count) == PINE_TREE || dwarf.look(r-count, c-count) == APPLE_TREE) {
    r -= count; c -= count;
    checkForSpace(dwarf, r, c, 1);
    return true;
  }
  if (dwarf.look(r+count, c-count) == PINE_TREE || dwarf.look(r+count, c-count) == APPLE_TREE) {
    r += count; c -= count;
    checkForSpace(dwarf, r, c, 1);
    return true;
  }
  if (dwarf.look(r-count, c+count) == PINE_TREE || dwarf.look(r-count, c+count) == APPLE_TREE) {
    r -= count; c += count;
    checkForSpace(dwarf, r, c, 1);
    return true;
  }
  if (count == ROWS) {
    stuck = true; 
    return false;
  }
  // recursively calls to check for tiles that are farther out
  lookForNextTree(dwarf, r, c, ++count);
}

bool lookForNextFence(Dwarf &dwarf, int &r, int &c, int count, Dir& d){
  if (dwarf.look(r, c+count) == FENCE) {
    c += count-2;
    d = EAST;
    return true;
  }
  if (dwarf.look(r, c-count) == FENCE) {
    c -= count-2;
    d = WEST;
    return true;
  }
  if (dwarf.look(r-count, c) == FENCE){
    r -= count-2;
    d = NORTH;
    return true;
  }
  if (dwarf.look(r+count, c) == FENCE) {
    r += count-2;
    d = SOUTH;
    return true;
  }
  // diagonals
  if (dwarf.look(r+count, c+count) == FENCE) {
    r += count; c += count;
    d = checkForSpace(dwarf, r, c, 2);
    return true;
  }
  if (dwarf.look(r-count, c-count) == FENCE) {
    r -= count; c -= count;
    d = checkForSpace(dwarf, r, c, 2);
    return true;
  }
  if (dwarf.look(r+count, c-count) == FENCE) {
    r += count; c -= count;
    d = checkForSpace(dwarf, r, c, 2);
    return true;
  }
  if (dwarf.look(r-count, c+count) == FENCE) {
    r -= count; c += count;
    d = checkForSpace(dwarf, r, c, 2);
    return true;
  }
  if (count == ROWS) {
    stuck = true; 
    return false;
  }
  // recursively calls to check for tiles that are farther out
  lookForNextFence(dwarf, r, c, ++count, d);
}

// this function will check if the dwarf is next to a tree
bool isNextToTree(Dwarf &dwarf, int &r, int &c, Dir &d){
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
// checks if dwarf is 2 tiles from a fence
bool isNextToFence(Dwarf &dwarf, int &r, int &c, Dir &d) {
  if (dwarf.look(r, c+2) == FENCE && dwarf.look(r, c+1) == EMPTY) {
    d = EAST;
    return true;
  }
  if (dwarf.look(r, c-2) == FENCE && dwarf.look(r, c-1) == EMPTY) {
    d = WEST;
    return true;
  }
  if (dwarf.look(r-2, c) == FENCE && dwarf.look(r-1, c) == EMPTY){
    d = NORTH;
    return true;
  }
  if (dwarf.look(r+2, c) == FENCE && dwarf.look(r+1, c) == EMPTY) {
    d = SOUTH;
    return true;
  }
  return false;
}

void goToRandomPosition(Dwarf& dwarf, ostream& log){
  int rr = rand() % ROWS; 
  int cc = rand() % COLS;
  log << "Dwarf " << dwarf.name() << " - Randomly walking to " << rr << " " << cc << "\n";
  dwarf.start_walk(rr, cc);
  stuck = false;
}
