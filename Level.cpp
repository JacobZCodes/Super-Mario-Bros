#include "Level.h"
#include "InputHandler.h"
#include "GameSymbols.h"
#include <random>
void Level::createBlankBoard(int size) {
    board = new char*[size];
    for (int row=0; row<size; row++) {
        board[row] = new char[size];
        for (int column = 0; column< size; column++) {
            board[row][column] = '!'; 
        }
    }
}

void Level::fillBlankBoard(int boardSize) {
    Coordinates position;
    int unitializedSquares = boardSize * boardSize; // board is a square
    initializeUniqueGameSymbols(boardSize, unitializedSquares); // pass squares by reference
}

Coordinates Level::findUnitializedSquare(int boardSize) {
    Coordinates position;
    while (true) {
        int row = rand() % boardSize;
        int column = rand() % boardSize;
        if (board[row][column] == '!') {
            position.row = row;
            position.column = column;
            return position;
        }
    }
}

// MARIO, BOWSER, WARP PIPE 
void Level::initializeUniqueGameSymbols(int boardSize, int uninitializedSquares) {
    Coordinates pos1 = findUnitializedSquare(boardSize);
    board[pos1.row][pos1.column] = MARIO;
    uninitializedSquares--;

    Coordinates pos2 = findUnitializedSquare(boardSize);
    board[pos2.row][pos2.column] = BOWSER;
    uninitializedSquares--;

    Coordinates pos3 = findUnitializedSquare(boardSize);
    board[pos3.row][pos3.column]  = WARP_PIPE;
    uninitializedSquares--;

    return;
}

// COIN, GOOMBA, KOOPA, MUSHROOM, EMPTY
void Level::initializeCommonGameSymbols(int boardSize, int unintializedSquares) {
    /* Each symbol maps to a different range of numbers depending on the user-inputted percentage */
    Range coinRange = {};
}