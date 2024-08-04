#include "GameSymbols.h"
#include <random>
#include <iostream>

const char MARIO = 'M';
const char BOWSER = 'B';
const char KOOPA = 'K';
const char GOOMBA = 'G';
const char MUSHROOM = 'M';
const char COIN = 'C';
const char WARP_PIPE = 'P';

GameSymbol::GameSymbol(Coordinates position, SymbolName name){
    this->position = position;
    this->name = name;
}

Mario::Mario(Coordinates position, SymbolName name) : GameSymbol(position, name) {
    this->HP = 3;
    this->powerLevel = 0;
    this->coins = 0;
    this->killCount = 0;
}

void Mario::takesDamage() {
    if (this->powerLevel != 0) {
        this->powerLevel--;
        return;
    }
    else if (this->HP > 1) {
        this->HP--;
        return;
    }
    else {
        std::cout << "Mario has died" << std::endl;
        exit(0);
    }

}

void Enemy::encounters(Mario* mario) {
    int encounterChance = (rand() % 100) + 1; // 1 - 100
    if (this->encounterChance <= encounterChance) { // Enemy wins
        mario->takesDamage();
        return;
    }
    else { // Enemy loses - If it's a boss, move Mario to next level. Otherwise, replace enemy with Mario.
        if (this->name.name == BOWSER) {
            std::cout << "Mario defeated a BOSS move him onwards! TO DO - IMPLEMENT NEXT LEVEL" << std::endl;
        }
        else {
            mario->position = this->position;
        }
        delete this; // remove symbol from board

    }

}

Bowser::Bowser(Coordinates position, SymbolName name) : GameSymbol(position, name) {
    this->encounterChance = 50;
}
