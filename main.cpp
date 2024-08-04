#include "InputHandler.h"
#include "GameSymbols.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    // InputHandler handler;
    // InitializationSpecs initializationSpecs = handler.askForInitializationSpecs();
    Coordinates coords = {10,4};
    SymbolName name = {'M'};
    Mario* newMario = new Mario(coords, name);
    
    return 0;
}
