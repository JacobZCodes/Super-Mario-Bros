// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Driver file
#include "World.h"
#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"
#include "time.h"
#include <iostream>

using namespace std;
int main() {
    srand(time(0));
    FileProcessor fp;
    World* myWorld = new World();
    myWorld->setWorldGameSpecs(fp.readFile("gamespecs.txt"));
    myWorld->returnWorldMario()->setV(myWorld->getWorldGameSpecs()[2]);
    myWorld->setLevelLimit(myWorld->getWorldGameSpecs()[0]);
    myWorld->startGame();
}