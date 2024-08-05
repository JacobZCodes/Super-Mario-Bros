#include "Level.h"
#include "InputHandler.h"
#include "GameSymbols.h"
#include <iostream>
#include <random>

void Level::createBlankBoard(int boardSize) {
    board = new GameSymbol**[boardSize];
    for (int row=0; row<boardSize; row++) {
        board[row] = new GameSymbol*[boardSize];
        for (int column = 0; column< boardSize; column++) {
            board[row][column] = nullptr;  
        }
    }
}

void Level::fillBlankBoard(int boardSize, InitializationSpecs initializationSpecs) {
    Coordinates position;
    int uninitializedSquares = boardSize * boardSize; // board is a square
    initializeUniqueGameSymbols(boardSize, uninitializedSquares);
    std::cout << "uninitialized squares is " << uninitializedSquares << std::endl;
    initializeCommonGameSymbols(boardSize, uninitializedSquares, initializationSpecs);

}

Coordinates Level::findUninitializedSquare(int boardSize) {
    Coordinates position;
    while (true) {
        int row = rand() % boardSize;
        int column = rand() % boardSize;
        if (board[row][column] == nullptr) {
            position.row = row;
            position.column = column;
            return position;
        }
    }
}

// MARIO, BOWSER, WARP PIPE 
void Level::initializeUniqueGameSymbols(int boardSize, int& uninitializedSquares) {
    Coordinates pos1 = findUninitializedSquare(boardSize);
    SymbolName mario = {MARIO};
    board[pos1.row][pos1.column] = new Mario(pos1, mario);
    uninitializedSquares--;


    Coordinates pos2 = findUninitializedSquare(boardSize);
    SymbolName bowser = {BOWSER};
    board[pos2.row][pos2.column] = new Enemy(pos2, bowser, 50);
    uninitializedSquares--;

    Coordinates pos3 = findUninitializedSquare(boardSize);
    SymbolName warpPipe = {WARP_PIPE};
    board[pos3.row][pos3.column]  = new GameSymbol(pos3, warpPipe);
    uninitializedSquares--;

    return;
}

SymbolName 
// COIN, GOOMBA, KOOPA, MUSHROOM, EMPTY
void Level::initializeCommonGameSymbols(int boardSize, int& unintializedSquares, InitializationSpecs initializationSpecs) {
    /* Each symbol maps to a different range of numbers depending on the user-inputted percentage */
    Range spawnCoinRange = {1, initializationSpecs.percentCoins};
    Range spawnGoombaRange = {spawnCoinRange.upper + 1, (spawnCoinRange.upper + initializationSpecs.percentGoombas)};
    Range spawnKoopaRange = {spawnGoombaRange.upper + 1, (spawnGoombaRange.upper + initializationSpecs.percentKoopas)};
    Range spawnMushroomRange = {spawnKoopaRange.upper + 1, (spawnKoopaRange.upper  + initializationSpecs.percentMushrooms)};
    Range spawnEmptyRange = {spawnMushroomRange.upper + 1, (spawnMushroomRange.upper  + initializationSpecs.percentEmpty)};

    int numUninitializedSquares = unintializedSquares;
    for (int i=numUninitializedSquares; i>0; i--) {
        int spawnChance = (rand() % 100) + 1; // 1 - 100

    }
    // std::cout << "Coin Range" << spawnCoinRange.lower << "to" << spawnCoinRange.upper << std::endl;
    // std::cout << "Goomba Range" << spawnGoombaRange.lower << "to" << spawnGoombaRange.upper << std::endl;
    // std::cout << "Koopa Range" << spawnKoopaRange.lower << "to" << spawnKoopaRange.upper << std::endl;
    // std::cout << "Mushroom Range" << spawnMushroomRange.lower << "to" << spawnMushroomRange.upper << std::endl;
    // std::cout << "Empty Range" << spawnEmptyRange.lower << "to" << spawnEmptyRange.upper << std::endl;

}