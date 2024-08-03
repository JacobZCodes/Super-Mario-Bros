#ifndef InputHandler_h
#define InputHandler_h

struct InitializationSpecs {
    int boardSize;
    int percentCoins;
    int percentGoombas;
    int percentKoopas;
    int percentMushrooms;
    int percentEmpty;
};

class InputHandler {
    public:
        InputHandler();
        int askForBoardSize();
        int askForPercentCoins();
        int askForPercentGoombas();
        int askForPercentKoopas();
        int askForPercentMushrooms();
        int askForPercentEmpty();
        InitializationSpecs askForInitializationSpecs();
};
#endif
