#ifndef GameSymbols_h
#define GameSymbols_h

extern const char MARIO;
extern const char BOWSER;
extern const char KOOPA;
extern const char GOOMBA;
extern const char MUSHROOM;
extern const char COIN;
extern const char WARP_PIPE;

struct SymbolName {
    char name;
};

struct Coordinates {
    int row;
    int column;
};


class GameSymbol {
    public:
        GameSymbol(Coordinates position, SymbolName name);
        Coordinates position;
        SymbolName name;

};

class Mario: public GameSymbol {
    public:
        Mario(Coordinates position, SymbolName name);
        int HP; // 3 HP to start with
        int powerLevel; // 0 - 2, tanks hit for HP
        int killCount; // +1 HP at 7 kills
        int coins; // +1 HP at 20 coins
        void takesDamage();
};  

class Enemy: virtual public GameSymbol {
    public:
        Enemy(Coordinates position, SymbolName name, int encounterChance);
        void encounters(Mario* mario); 
        int encounterChance; // to beat Mario in a fight
};


#endif // GameSymbols_h
