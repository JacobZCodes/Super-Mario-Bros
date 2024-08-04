// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Implementation file for a World class
#include "World.h"
#include "Mario.h"
#include "Level.h"
#include <iostream>
using namespace std;

World::World() {
    this->levelCounter = 0;
    this->worldMario = new Mario();
    this->fp = new FileProcessor();
}

Mario* World::returnWorldMario() {
    return this->worldMario;
}

void World::setLevelLimit(int L) { // Based on gamespecs.txt
    this->L = L;
}

void World::setWorldGameSpecs(int* gameSpecs) { // Utilizes our FileProcessor class to read in gamespecs.txt
    this->worldGameSpecs = gameSpecs;
}

void World::startGame() {
    this->currentLevel = this->createNewLevel(this->worldGameSpecs[1], this->worldMario, 
    this->worldGameSpecs[3], this->worldGameSpecs[5], this->worldGameSpecs[6], this->worldGameSpecs[7], 
    this->worldGameSpecs[4]); 
    // currentLevel increments our levelCounter by one, so right off the bat we're starting at Level 1,
    // which is why L in the below while loop needs to have that +1 tagged on
    while (this->levelCounter < (this->L) + 1) { 
        // Pretty logging
        this->fp->logEntry("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "gamelog.txt");
        this->fp->logEntry("LEVEL " + to_string(this->levelCounter), "gamelog.txt");
        // updateBoard provides the necessary information for the rest of the logs to work properly
        // - they all depend on values that updateBoard updates
        this->currentLevel->updateBoard();
        this->returnWorldMario()->logPosition(); // (3,4)
        this->currentLevel->logPowerLevel(); 
        this->fp->logEntry(this->currentLevel->getEncounter(), "gamelog.txt"); // Mario encounters an empty square etc
        this->fp->logEntry("Lives: " + to_string(this->returnWorldMario()->getV()), "gamelog.txt");  
        this->fp->logEntry("Coins: " + to_string(this->returnWorldMario()->getCoinPouch()), "gamelog.txt");
        this->returnWorldMario()->logMove(); // Mario moves UP etc
        this->currentLevel->logGrid(); // Visual representation of our 2D array board
        if (this->currentLevel->getLevelOver() == true) {
            delete this->currentLevel;
            if (this->levelCounter == this->L) { 
                this->fp->logEntry("MARIO DEFEATED THE FINAL BOSS AND SAVED THE PRINCESS!", "gamelog.txt");
                exit(1);
            }
            this->currentLevel = this->createNewLevel(this->worldGameSpecs[1], this->worldMario, 
            this->worldGameSpecs[3], this->worldGameSpecs[5], this->worldGameSpecs[6], this->worldGameSpecs[7], 
            this->worldGameSpecs[4]);
        }
    } 
}

int* World::getWorldGameSpecs() {
    return this->worldGameSpecs;
}

// Creates a pointer to a new Level and returns it
Level* World::createNewLevel(int N, Mario* p_mario, int percentCoins, int percentGoombas, 
int percentKoopas, int percentMushrooms, int percentNothing) {
    Level* newLevel = new Level(this->worldGameSpecs[1], p_mario, this->worldGameSpecs[3], 
    this->worldGameSpecs[5], this->worldGameSpecs[6], this->worldGameSpecs[7], this->worldGameSpecs[4]);
    levelCounter++;
    // If our current level is equal to the total number of levels,
    // we are on the final level, so we omit a warp pipe by calling populateFinalGrid
    if (levelCounter == L) {
        newLevel->populateFinalGrid();
    }
    else {
        newLevel->populateGrid();
    }
    return newLevel;
}