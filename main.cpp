#include "InputHandler.h"
#include "GameSymbols.h"
#include "Level.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    InputHandler handler;
    InitializationSpecs initializationSpecs = handler.askForInitializationSpecs();
    Level level;
    level.createBlankBoard(initializationSpecs.boardSize);
    level.fillBlankBoard(initializationSpecs.boardSize, initializationSpecs);
    
    return 0;
}
