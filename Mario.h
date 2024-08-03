// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Header file for a Mario class
#ifndef MARIO_H
#define MARIO_H
#include "FileProcessor.h"
#include "Level.h"
// CITE - CHATGPT
class Level;
// I had to look to ChatGPT for this one. I want Mario to be able to access certain properties
// Level, but I don't want to mess with inheritance. This is apparentyl called a forward
// declaration, which behaves somewhat similarly to inheritance and suits my purposes here.
class Mario{
    public:
        Mario(); // Default Constructor
        virtual ~Mario(); // Destructor
        // Mutators
        void setInitialRow(int row);
        void setInitialColumn(int column);
        void setMarioPreviousRow(int row);
        void setMarioPreviousColumn(int column);
        void setMarioRow(int row);
        void setMarioColumn(int column);
        void setV(int V);
        void setDirection(string dir);
        // Accessors
        int getMarioPreviousRow();
        int getMarioPreviousColumn();
        int getMarioRow();
        int getMarioColumn();
        int getGridDimensions(Level& level); // This is why I needed a forward declaration of Level
        int getNumMoves();
        int getInitialRow();
        int getInitialColumn();
        int getV();
        int getCoinPouch();
        int getPL();
        int getKillCount();
        string getDirection();
        // Misc
        int incrementNumMoves();
        void logPosition();
        void logMove();
        void gainPL();
        void grabCoin();
        void killsEnemy();
        void takesDamage();
    
    private:
        int V; // V Lives
        int coinPouch; // 20 coins = 1 life
        int PL; // Power Level (PL0 - PL2)
        int killCount; // Tracks enemies defeated per life
        int marioRow;
        int marioColumn;
        int marioPreviousRow;
        int marioPreviousColumn;
        int initialRow;
        int initialColumn;
        bool hasTakenFirstMove;
        int numMoves;
        string nextDirection;
        FileProcessor* fp;
};
#endif