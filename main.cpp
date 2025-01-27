#include<iostream>
#include "system.h"

int main(){
    System model(100, 20.0, 0.5, 0.1, 2025);
    model.randomStart();
    std::string root = "frames/frame";

    for(int i = 0; i<= 5; i++){
        model.saveConfig(root + std::to_string(i));
        model.updateRule();
    }

    return 0;
}
