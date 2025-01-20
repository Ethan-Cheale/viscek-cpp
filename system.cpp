#include <iostream>
#include "system.h"
#include "box.h"
#include "particle.h"

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
    //initialising Box
    this->simulationBox.setSides(sideLength,sideLength);
    this->simulationBox.setOrigin(0,0);
    //initialising particle vector
    this->particles.resize(particleNumber);
    std::cout<<"I am constructing the System!\n";
}
