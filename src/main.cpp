// main.cpp
#include "MazeGame.hpp"
#include <iostream>

int main() {
    try {
        MazeGame game;
        game.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}