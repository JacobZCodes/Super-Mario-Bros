#include "InputHandler.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    InputHandler handler;
    InitializationSpecs initializationSpecs = handler.askForInitializationSpecs();
    
    return 0;
}
