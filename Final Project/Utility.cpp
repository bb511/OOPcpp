#include "Utility.h"

double generateRandomNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

void animateCharSpeech(std::string line){
    while ( line[idx] != '\0')
    {
        std::cout << line[idx];
        Sleep(500);
        idx++;
    };
}
