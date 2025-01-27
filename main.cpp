#include<iostream>
#include "system.h"

int main(){
    System test(100, 20.0, 0.5, 0.1, 2025);
    test.updateRule();
    std::cout << "The System has a simulation box of side "<<test.simulationBox.getSidex()<<std::endl;
    std::cout << "Random number test "<< test.uniform(10,20) <<std::endl;
    return 0;
}
