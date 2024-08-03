#ifndef Level_h
#define Level_h
struct Coordinates {
    int row;
    int column;
};

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
        char** board;
};  
#endif