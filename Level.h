#ifndef Level_h
#define Level_h
#include "GameSymbols.h"
#include "InputHandler.h"


struct Range {
    int lower;
    int upper;
};

class Level {
    public:
        void createBlankBoard(int boardSize);
        void fillBlankBoard(int boardSize, InitializationSpecs initializationSpecs);
        Coordinates findUninitializedSquare(int boardSize);
        void initializeUniqueGameSymbols(int boardSize, int& uninitializedSquares);
        void initializeCommonGameSymbols(int boardSize, int& uninitializedSquares, InitializationSpecs initializationSpecs);
        // SymbolName createSymbol(Range r1, Range r2, Range r)
    private:
        GameSymbol*** board; // needs to be triple pointer because we can't do new GameSymbol[board] because this implies we know the size of a GameSymbol at compile time, which we don't since I don't
                             // know what a default GameSymbol object looks like since my program doesn't call for default GameSymbol objects -- see createBlankBoard()
};  
#endif