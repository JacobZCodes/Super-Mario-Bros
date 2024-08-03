// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Header file for a World class
#ifndef WORLD_H
#define WORLD_H
#include "FileProcessor.h"
// Forward declarations
class Mario;
class Level;
class World
{
public:
    World();
    void startGame();
    Mario* returnWorldMario();
    Level* createNewLevel(int N, Mario* p_mario, int percentCoins, int percentGoombas, int percentKoopas, int percentMushrooms, int percentNothing);
    void setWorldGameSpecs(int* gameSpecs);
    int* getWorldGameSpecs();
    void setLevelLimit(int L);

private:
    Level* currentLevel;
    int L;
    int levelCounter;
    int* worldGameSpecs;
    Mario* worldMario;
    FileProcessor* fp;
};
#endif
