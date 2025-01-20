#include<iostream>
#include "system.h"

int main(){
    System test(100, 20,0.5,0.1);
    test.updateRule();
    std::cout << "particleNumber " << test.particleNumber << "\n";
    return 0;
}
