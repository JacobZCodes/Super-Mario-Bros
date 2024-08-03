// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Header file for a Level class
#ifndef LEVEL_H
#define LEVEL_H
#include "FileProcessor.h"
class Mario;
class Level {
    public:
        Level(int N, Mario* p_mario, int percentCoins, int percentGoombas, int percentKoopas, int percentMushrooms, int percentNothing); // Overloaded Constructor takes a command line parameter - creates an NxN grid filled with '!'
        virtual ~Level(); // Default Destructor
        // Mutators
        void populateGrid(); // Takes our '!'-filled grid and populates it with game components
        void populateFinalGrid(); // Same as populateGrid save omitting the 'w' square
        // Accessors
        Mario* getMario();
        int getSize();
        void updateBoard();
        void resolveEncounter();
        void updateMario();
        bool getLevelOver();
        void printGrid(); // Prints grid to terminal
        char componentForPreviousSquare; // What to set Mario's previous square to after he leaves
        int percentCoins;
        int percentMushrooms;
        int percentGoombas;
        int percentKoopas;
        int percentNothing;
        void logGrid();
        char **getGrid();
        void logPowerLevel();
        string getEncounter();
        void setCurrentEncounter(string encounter);

    private:
        Mario* mario;
        int rowNumber = 1;
        int columnNumber = 1;
        char **grid;
        int N; // Stores dimensions
        bool lostEncounter;
        char latestLostToEnemy;
        char componentLandedOn;
        bool levelOver;
        FileProcessor* fp;
        string encounter;
};
#endif