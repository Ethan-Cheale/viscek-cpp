#include <iostream>
#include "system.h"
#include "box.h"

// The update rule
void System::updateRule(){
    std::cout<<"Updating the system...\n";
}

// Defining the constructor
System::System(int particleNumber, double sideLength, double timeStep,double noiseStrength){
    this->particleNumber = particleNumber;
    this->noiseStrength = noiseStrength;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    this->simulationBox.setSides(sideLength,sideLength);
    this->simulationBox.setOrigin(0,0);
    std::cout<<"I am constructing the System!\n";
}
