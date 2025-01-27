#include <iostream>
#include "system.h"
#include "box.h"
#include "particle.h"

// The update rule
void System::updateRule(){
    std::cout<<"Updating the system...\n";
}

// Defining the constructor
System::System(int particleNumber, double sideLength, double timeStep,double noiseStrength, int seed){
    //initialising variables
    this->particleNumber = particleNumber;
    this->noiseStrength = noiseStrength;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    //initialising Box
    this->simulationBox.setSides(sideLength,sideLength);
    this->simulationBox.setOrigin(0,0);
    //initialising particle vector
    this->particles.resize(particleNumber);
    //initialising generator
    this->gen = std::mt19937(seed);
    std::cout<<"I am constructing the System!\n";
}

// Defining uniform function
double System::uniform(double min, double max){
    return (max-min)*this->uniformDist(gen)+ min;
}