#include<iostream>
#include "system.h"

int main(){
    System test(100, 20,0.5,0.1);
    test.updateRule();
    std::cout << "The System has a simulation box of side "<<test.simulationBox.getSidex()<<std::endl;
    return 0;
}
