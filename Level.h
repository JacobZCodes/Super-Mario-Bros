#ifndef Level_h
#define Level_h
#include "GameSymbols.h"


struct Range {
    int lower;
    int upper;
};

class Level {
    public:
        void createBlankBoard(int size);
        void fillBlankBoard(int boardSize);
        Coordinates findUnitializedSquare(int boardSize);
        void initializeUniqueGameSymbols(int boardSize, int uninitializedSquares);
        void initializeCommonGameSymbols(int boardSize, int uninitializedSquares);
    private:
        GameSymbol** board;
};  
#endif