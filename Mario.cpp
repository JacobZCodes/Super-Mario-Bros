// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Implementation file for a Mario class
#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Mario::Mario(){
    V = 3; // Altered at runtime
    coinPouch = 0;
    PL = 0;
    killCount = 0;
    numMoves = 0;
    FileProcessor* fp = new FileProcessor();
}

Mario::~Mario() {}

// Helper functions to log Mario's directional info to gamelog.txt
void Mario::logPosition() {
    this->fp->logEntry("Mario is at (" + to_string(this->getMarioRow()) + "," + to_string(this->getMarioColumn()) + ")", "gamelog.txt");
}

void Mario::logMove() {
    this->fp->logEntry("Mario will move " + this->nextDirection, "gamelog.txt");
}

void Mario::setDirection(string dir) {
    this->nextDirection = dir;
}

// General helper functions
void Mario::gainPL() {
    if (PL == 2) {
        ;
    }
    else {
        PL++;
    }
}

int Mario::getV() {
    return this->V;
}
int Mario::getCoinPouch(){
    return this->coinPouch;
}

int Mario::getPL(){
    return this->PL;
}

int Mario::getKillCount(){
    return this->killCount;
}

void Mario::grabCoin() {
    coinPouch++;
    if (coinPouch == 20) { 
        V++;
        coinPouch = 0;
    }
}

void Mario::killsEnemy() {
    killCount++;
    if (killCount % 7 == 0) { // Every 7 kills Mario gains a life.
        V++;
        killCount = 0;
    }
}

void Mario::takesDamage() {
    if (PL == 0) {
        V--;
        killCount = 0; // killCount resets when Mario loses a life
        if (V == 0) { // If V == 0, Mario dies
            this->fp->logEntry("Mario was slain by a valiant foe", "gamelog.txt");
            exit(1);
        }
    }
    else {
        PL--;
    }
}

void Mario::setMarioRow(int row) {
    this->marioRow = row;
}

void Mario::setMarioColumn(int column) {
    this->marioColumn = column;
}

void Mario::setInitialRow(int row) {
    this->initialRow = row;
}

void Mario::setInitialColumn(int column) {
    this->initialColumn = column;
}

int Mario::getMarioRow() {
    return marioRow;
}

int Mario::getMarioColumn() {
    return marioColumn;
}

int Mario::getGridDimensions(Level& level) {
    return level.getSize();
}

int Mario::getMarioPreviousRow() {
    return marioPreviousRow;
}

int Mario::getMarioPreviousColumn() {
    return marioPreviousColumn;
}

int Mario::getNumMoves() {
    return this->numMoves;
}

int Mario::getInitialRow() {
    return this->initialRow;
}

int Mario::getInitialColumn() {
    return this->initialColumn;
}

void Mario::setMarioPreviousRow(int row) {
    this->marioPreviousRow = row;
}

void Mario::setMarioPreviousColumn(int column) {
    this->marioPreviousColumn = column;
}

int Mario::incrementNumMoves() {
    this->numMoves++;
}

void Mario::setV(int V) {
    this->V = V;
}

string Mario::getDirection() {
    return this->nextDirection;
}







