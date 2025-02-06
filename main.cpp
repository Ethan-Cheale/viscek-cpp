#include<iostream>
#include<cstdlib>
#include "system.h"

int main(int argc, char* argv[]){
    double noiseStrength = std::stof(argv[1]);

    std::string root = "frames/frame";
    System model(100, 20.0, 0.5, noiseStrength, 2020);
    model.randomStart();
    model.saveConfig(root + std::to_string(0));

    for(int i = 1; i<= 200; i++){
        model.updateRule();
        model.saveConfig(root + std::to_string(i));
    }

    return 0;
}
