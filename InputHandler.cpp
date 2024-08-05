#include "InputHandler.h"
#include <iostream>
#include <string>
#include <stdexcept>


InputHandler::InputHandler() {
    ; // do nothing
}

int InputHandler::askForBoardSize() {
    std::string input;
    int boardSize;
    while (true){
        std::cout << "Enter a positive integer representing the NxN dimensions of the game board: ";
        std::getline(std::cin, input);

        try {
            size_t pos; 
            boardSize = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (boardSize <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return boardSize;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}

int InputHandler::askForPercentCoins() {
    std::string input;
    int percent;
    while (true){
        std::cout << "Enter a positive integer representing the percent of squares occupied by COINS: ";
        std::getline(std::cin, input);

        try {
            size_t pos; 
            percent = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (percent <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return percent;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}


int InputHandler::askForPercentGoombas() {
    std::string input;
    int percent;
    while (true){
        std::cout << "Enter a positive integer representing the percent of squares occupied by GOOMBAS: ";
        std::getline(std::cin, input);

        try {
            size_t pos; 
            percent = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (percent <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return percent;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}

int InputHandler::askForPercentKoopas() {
    std::string input;
    int percent;
    while (true){
        std::cout << "Enter a positive integer representing the percent of squares occupied by KOOPAS: ";
        std::getline(std::cin, input);

        try {
            size_t pos; 
            percent = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (percent <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return percent;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}

int InputHandler::askForPercentMushrooms() {
    std::string input;
    int percent;
    while (true){
        std::cout << "Enter a positive integer representing the percent of squares occupied by MUSHROOMS: ";
        std::getline(std::cin, input);

        try {
            size_t pos; 
            percent = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (percent <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return percent;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}

int InputHandler::askForPercentEmpty() {
    std::string input;
    int percent;
    while (true){
        std::cout << "Enter a positive integer representing the percent of squares occupied by EMPTY: ";        
        std::getline(std::cin, input);
        try {
            size_t pos; 
            percent = std::stoi(input, &pos);

            // Check if there are any non-numeric characters left in the input or if input is a float
            if (pos < input.size() || input.find('.') != std::string::npos) {
                throw std::invalid_argument("Input contains non-numeric characters or is a decimal.");
            }
            
            if (percent <= 0) {
                throw std::invalid_argument("Input must be positive.");
            }

            return percent;
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Out of range. " << e.what() << std::endl;
        }
    }
}

InitializationSpecs InputHandler::askForInitializationSpecs(){
    int boardSize = askForBoardSize();
    int percentCoins, percentGoombas, percentKoopas, percentMushrooms, percentEmpty;
    while (true){
        percentCoins = askForPercentCoins();
        percentGoombas = askForPercentGoombas();
        percentKoopas = askForPercentKoopas();
        percentMushrooms = askForPercentMushrooms();
        percentEmpty = askForPercentEmpty();
        int totalPercent = percentCoins + percentGoombas + percentKoopas + percentMushrooms + percentEmpty;
        if (totalPercent != 100) {
            std::cout << "Total percent must add up to 100 (" << totalPercent << ")" << std::endl;
        }
        else {
            break;
        }
    }
    InitializationSpecs specs = {
        boardSize, 
        percentCoins, 
        percentGoombas, 
        percentKoopas, 
        percentMushrooms, 
        percentEmpty
    }; 
    return specs;
}