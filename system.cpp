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

void System::randomStart(){
    for (Particle &p: this->particles){
        p.x = this->uniform(0, this->simulationBox.getSidex());
        p.y = this->uniform(0, this->simulationBox.getSidey());
        p.theta = this->uniform(M_PI * -1, M_PI);
    }
}

void System::saveConfig(const std::string &filename)
{   
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return; // Exit if file cannot be opened
    }
    outFile << std::to_string(particles.size())+"\nParticles"<<std::endl;
    
    // Write particle properties to the file

    for (size_t i = 0; i < particles.size(); ++i) {
        outFile << i << " " << particles[i].x <<" "<<particles[i].y<<" "<<particles[i].theta << std::endl;
    }
    outFile.close(); // Close the file
} 