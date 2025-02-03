#include<iostream>
#include "system.h"

int main(){
    std::string root = "frames/frame";
    System model(100, 20.0, 0.5, 0.1, 2025);
    model.randomStart();
    model.saveConfig(root + std::to_string(0));

    for(int i = 1; i<= 200; i++){
        model.updateRule();
        model.saveConfig(root + std::to_string(i));
    }

    return 0;
}
