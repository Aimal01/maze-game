#pragma once
#include <string>
#include <iostream>

class GameInfo {
public:
    static const std::string CURRENT_DATE;
    static const std::string CURRENT_USER;
    
    static void printGameInfo() {
        std::cout << "Game started by " << CURRENT_USER << " on " << CURRENT_DATE << std::endl;
    }
};

const std::string GameInfo::CURRENT_DATE = "2025-04-29 07:13:49";
const std::string GameInfo::CURRENT_USER = "Aimal01";