// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Implementation file for a Level class

#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

Level::Level(int N, Mario* p_mario, int percentCoins, int percentGoombas, int percentKoopas, int percentMushrooms, int percentNothing) {
    levelOver = false; // Bool for World.cpp
    lostEncounter = false; // Bool to help in updateBoard()
    this->mario = p_mario; // Pointer to Mario
    this->N = N; // Reads from input file
    this->percentCoins = percentCoins; 
    this->percentGoombas = percentGoombas;
    this->percentKoopas = percentKoopas;
    this->percentMushrooms = percentMushrooms;
    this->percentNothing = percentNothing;
    // grid is an array of pointers that are pointing to specific addresses in memory 
    // that can only be taken up by chars or arrays of chars
    grid = new char*[N];
    // this for loop instantiates an empty array for every element in grid. 
    // grid[i] was previously pointing to an address in memory, but now it is
    // storing an empty char array of length N
    for (int i = 0; i < N; ++i) {
        grid[i] = new char[N];
    }
    // this below for-loop actually populates the array
    for (int i = 0; i < N; ++i) {
        // each element of grid is its own char array,
        // so we need to loop through that and populate it
        for (int j = 0; j < N; ++j) {
                grid[i][j] = '!';
        }
            // thinking of grid as an actual "grid", 
            // the i will represent our row and j our column
    }
}

void Level::printGrid(){
    for (int col = 0; col < N; ++col) {
        // Column Headers
    }
    for (int i = 0; i < N; ++i) { 
        // Prints rows
        for (int j = 0; j < N ; ++j) {
        }
    }
}

char** Level::getGrid() {
    // I was having some crazy multi-threading issue with my logGrid() function and
    // this semeed to fix it
    return this->grid;
}
void Level::logGrid(){
    // Logs grid to gamelog.txt
    int gridSize = this->N;
    string* gridRows = new string[gridSize + 1];
    // gridRows needs to account for the additional row that represents our column headers; why the +1 is needed
    gridRows[0] = "   ";
    for (int col = 0; col < N; ++col) {
        // Column Headers
        gridRows[0] += to_string(col) + " ";
    }
    for (int i = 0; i < N; ++i) { 
        // We need to start from i + 1 in grid rows
        // since our 0th index holds the column headers
        gridRows[i + 1] += to_string(i) + "| ";
        for (int j = 0; j < N ; ++j) {
            gridRows[i + 1] = gridRows[i + 1] + this->getGrid()[i][j] + " ";
        }
    }
    for (int i = 0; i < gridSize+1; ++i) {
        this->fp->logEntry(gridRows[i], "gamelog.txt");
    }
}

Level::~Level(){
    for (int i = 0; i < N; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

int Level::getSize() {
    return this->N;
}

void Level::populateFinalGrid() {
    // Exact same as populateGrid except now we don't have a warp
    // CITE - https://www.youtube.com/watch?v=CJ37J_Cdd8Q - randomness
    int emptySquares = N * N;
    char uniqueItems[] = {'H','b'};

    for (int i = 0; i < 2; ++i) {
        // Loop through uniqueItems and populate each one on the grid
        while (true) {
            int tempRow = rand() % N;
            int tempColumn = rand() % N;
            if (i == 0) {
                this->mario->setMarioRow(tempRow); 
                this->mario->setMarioColumn(tempColumn);
                this->mario->setInitialRow(tempRow);
                this->mario->setInitialColumn(tempColumn);
            }
            if (grid[tempRow][tempColumn] == '!') {
                grid[tempRow][tempColumn] = uniqueItems[i];
                emptySquares--;
                break;
            }
        }
    }
    char standardItems[] = {'c','m','g','k','x'};
    while(emptySquares != 0) {
        // Handle user-specificed percentages here with a series of conditionals
        char randomGameComponent;
        int numToDecideComponent = rand() % 100; // 0 - 99
        // c - 15
        // m - 20
        // g - 40
        // k - 10
        // x - 15
        if (numToDecideComponent < percentCoins) { // c(15) - 0-14
            randomGameComponent = 'c';
        }
        else if (numToDecideComponent >= percentCoins && numToDecideComponent < (percentCoins + percentMushrooms)) {
            // m(20) - 15 - 34 
            randomGameComponent = 'm';
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas)) {
            randomGameComponent = 'g';
            // g(40) - 35 - 74
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms + percentGoombas) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas + percentKoopas)) {
            // k(10) 75 - 84
            randomGameComponent = 'k';
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms + percentGoombas + percentKoopas) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas + percentKoopas + percentNothing)) {
            // x(15) 85 - 99 
            randomGameComponent = 'x';
        }
        int tempRow = rand() % N;
        int tempColumn = rand() % N;
        if (grid[tempRow][tempColumn] == '!') {
            grid[tempRow][tempColumn] = randomGameComponent;
            emptySquares--;
        }
    }
    this->printGrid();
}

void Level::populateGrid(){
    // CITE - https://www.youtube.com/watch?v=CJ37J_Cdd8Q - randomness
    int emptySquares = N * N;
    char uniqueItems[] = {'H', 'w', 'b'};

    for (int i = 0; i < 3; ++i) {
        // Loop through uniqueItems and populate each one on the grid
        while (true) {
            int tempRow = rand() % N;
            int tempColumn = rand() % N;
            if (i == 0) {
                this->mario->setMarioRow(tempRow); 
                this->mario->setMarioColumn(tempColumn);
                this->mario->setInitialRow(tempRow);
                this->mario->setInitialColumn(tempColumn);
            }
            if (grid[tempRow][tempColumn] == '!') {
                grid[tempRow][tempColumn] = uniqueItems[i];
                emptySquares--;
                break;
            }
        }
    }
    char standardItems[] = {'c','m','g','k','x'};
    while(emptySquares != 0) {
        // Handle user-specificed percentages here with a series of conditionals
        char randomGameComponent;
        int numToDecideComponent = rand() % 100; // 0 - 99
        // c - 15
        // m - 20
        // g - 40
        // k - 10
        // x - 15
        if (numToDecideComponent < percentCoins) { // c(15) - 0-14
            randomGameComponent = 'c';
        }
        else if (numToDecideComponent >= percentCoins && numToDecideComponent < (percentCoins + percentMushrooms)) {
            // m(20) - 15 - 34 
            randomGameComponent = 'm';
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas)) {
            randomGameComponent = 'g';
            // g(40) - 35 - 74
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms + percentGoombas) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas + percentKoopas)) {
            // k(10) 75 - 84
            randomGameComponent = 'k';
        }
        else if (numToDecideComponent >= (percentCoins + percentMushrooms + percentGoombas + percentKoopas) && numToDecideComponent < (percentCoins + percentMushrooms + percentGoombas + percentKoopas + percentNothing)) {
            // x(15) 85 - 99 
            randomGameComponent = 'x';
        }
        int tempRow = rand() % N;
        int tempColumn = rand() % N;
        if (grid[tempRow][tempColumn] == '!') {
            grid[tempRow][tempColumn] = randomGameComponent;
            emptySquares--;
        }
    }
    // cout <<  "POPULATING A NEW GRID..." << endl;
    this->printGrid();
}

Mario* Level::getMario() {
    return mario;
}

bool Level::getLevelOver() {
    return this->levelOver;
}

void Level::updateMario() {
    // Keep track of Mario's previous position by grabbing his coordinates
    // right before he moves
    string move;
    this->getMario()->setMarioPreviousRow(this->getMario()->getMarioRow());
    this->getMario()->setMarioPreviousColumn(this->getMario()->getMarioColumn());
    int lb = 1;
    int ub = 4;
    int direction;
    direction = rand() % (ub - lb + 1) + lb ;
    // 1 - Up, 2 - Down, 3 - Right, 4 - Left
    if (direction == 1) {
        // Up
        if (this->getMario()->getMarioRow() == 0) {
            this->getMario()->setMarioRow(N-1);
        }
        else {
            this->getMario()->setMarioRow((this->getMario()->getMarioRow()) - 1);
        }
        move = "UP";
        this->getMario()->setDirection("UP");
    }  
    else if (direction == 2) {
        // Down
        if (this->getMario()->getMarioRow() == this->N - 1){
            this->getMario()->setMarioRow(0);
        }
        else {
            this->getMario()->setMarioRow((this->getMario()->getMarioRow()) + 1);
        }
        move = "DOWN";
        this->getMario()->setDirection("UP");

    }
    else if (direction == 3) {
        // Right
        if (this->getMario()->getMarioColumn() == N - 1){
            this->getMario()->setMarioColumn(0);
        }
        else {
            this->getMario()->setMarioColumn((this->getMario()->getMarioColumn()) + 1);
        }
        move = "RIGHT";
        this->getMario()->setDirection("RIGHT");

    }
    else if (direction == 4) {
        // Left
        if (this->getMario()->getMarioColumn() == 0){
            this->getMario()->setMarioColumn(N - 1);
        }
        else {
            this->getMario()->setMarioColumn((this->getMario()->getMarioColumn())- 1);
        }
        move = "LEFT";
        this->getMario()->setDirection("UP");


    }
    this->getMario()->incrementNumMoves();
}

string Level::getEncounter() {
    // Helper function for World.cpp
    return this->encounter;
}

void Level::setCurrentEncounter(string encounter) {
    this->encounter = encounter;
}
void Level::logPowerLevel() {
    this->fp->logEntry("Power Level " + to_string(this->getMario()->getPL()), "gamelog.txt");
}
void Level::updateBoard() {
    // Handles encounters based on what space Mario is currently on
    this->updateMario();
    // MarioPreviousRow + MarioPreviousColumn set to current position
    // MarioRow + MarioColumn set to new position
    if((grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'x'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'c'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'm'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'w') &&
    (!lostEncounter)) 
    { 
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'x') {
            this->encounter = "Mario encounters an empty space";
        }
        // If c or m, update Mario's stats acoordingly
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'c') {
            this->getMario()->grabCoin();
            this->encounter = "Mario picks up a coin";

        }
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'm') {
            this->getMario()->gainPL();
            this->encounter = "Mario picks up a mushroom";
        }
        // If w, change levelOver status to true. Our World class will check for this and then call the Level
        // destructor, and will then instantiate a new level.
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'w') {
            this->encounter = "Mario finds a warp pipe!";
            levelOver = true;
        }
        // If Mario lands on a non-enemy square and his bool lostEncounter is false,
        // that means he either defeated an enemy or just left a non-enemy square;
        // in either instance, that space will be set to 'x'.
        grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] = 'x';
        grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] = 'H';
        this->printGrid();
    }
    else if((grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'x'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'c'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'm'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'w') &&
    (lostEncounter))  {
        // If an x, just log it
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'x') {
            this->encounter = "Mario encounters an empty space";
        }
        // If c or m, update Mario's stats acoordingly
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'c') {
            this->getMario()->grabCoin();
            this->encounter = "Mario picks up a coin";
        }
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'm') {
            this->getMario()->gainPL();
            this->encounter = "Mario picks up a mushroom";
        }
        // If w, change levelOver status to true. Our World class will check for this and then call the Level
        // destructor, and will then instantiate a new level.
        if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'w') {
            this->encounter = "Mario finds a warp pipe!";
            levelOver = true;
        }
        // If Mario lands on a non-enemy square right after losing to an enemy, place him
        // on the space and update our lostEncounter bool - we don't want to mess
        // with the previous square here, as it should still rightfully contain the enemy.
        grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] = 'H';
        this->printGrid();
        lostEncounter = false;
    }
    else if(grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'b'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'g'
    || grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'k')
    {
        this->resolveEncounter();
        if (!lostEncounter) {
            // First update Mario's stats
            this->getMario()->killsEnemy();
            // Mario won the encounter. If he just got out of a previous encounter and lost
            // to that enemy, we don't want to set that square to x, so we need
            // a conditional here to check.
            if (grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] == 'b'
                ||grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] == 'k'
                ||grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] == 'g'
                )
            {
                grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] = 'H';
                this->printGrid();
            }
            else{
                grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] = 'x';
                grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] = 'H';
                this->printGrid();
            }
        }
        else if (lostEncounter) {
            // First, update Mario's stats.
            this->getMario()->takesDamage();
            // Mario lost the encounter. Mario's H hasn't phsyically moved on the board yet as he isn't occupying
            // the square - he lost, so he needs to move on, but we don't want to leave the H stuck behind.
            if (grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] == 'H') {
                grid[this->getMario()->getMarioPreviousRow()][this->getMario()->getMarioPreviousColumn()] = 'x';
            }
            else {
                ;
            }
            // If Mario loses the encounter, we just want him to keep moving on.
            // When updateBoard is called again, he will just move on.
        }
    }
}
void Level::resolveEncounter() {
    // Handles combat
    this->lostEncounter = false;
    int successProbability; // Will determine whether Mario wins or loses his fights
    if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'k') {
        successProbability = rand() % 100;
        // For Koopas, Mario wins with 65% probability
        if (successProbability < 65) {
            this->encounter = "Mario defeats Koopa!";
            lostEncounter = false;
        }
        else if (successProbability >= 65) {
            this->encounter = "Koopa defeats Mario!";
            lostEncounter = true;
        }
    }
    else if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'g') {
        // For Goombas, Mario wins with 80% probability
        successProbability = rand() % 100;
        if (successProbability < 80) {
            this->encounter = "Mario defeats Goomba!";
            lostEncounter = false;
        }
        else if (successProbability >= 80) {
            this->encounter = "Goomba defeats Mario!";
            lostEncounter = true;
        }
    }
    else if (grid[this->getMario()->getMarioRow()][this->getMario()->getMarioColumn()] == 'b') {
        // For Bosses, Mario wins with 50% probability
        successProbability = rand() % 100;
        if (successProbability < 50) {
            this->encounter = "Mario defeats Boss!";
            // cout << "Mario defeats Boss" << endl;
            lostEncounter = false;
            levelOver = true;
        }
        else if (successProbability >= 50) {
            this->encounter = "Boss defeats Mario!";
            lostEncounter = true;
        }
    }
}