#include <iostream>

#include "system.h"
#include "box.h"
#include "particle.h"

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

// The update rule
void System::updateRule(){
    // Calculating the new angle of travel for the particle
    std::vector<double> new_thetas;
    for (Particle &current_particle: this->particles){
        double neighbour_count = 0;
        double neighbour_sin = 0.0;
        double neighbour_cos = 0.0;
        for (Particle &neighbour_particle: this->particles){
            if (std::sqrt(std::pow(current_particle.x-neighbour_particle.x,2.0) + std::pow(current_particle.y-neighbour_particle.y,2.0)) <= 1.0){   
                neighbour_count += 1;
                neighbour_sin += std::sin(neighbour_particle.theta);
                neighbour_cos += std::cos(neighbour_particle.theta);
            }
        }
        double avg_theta = std::atan2(neighbour_sin/neighbour_count,neighbour_cos/neighbour_count);
        //avg_theta += this->uniform(this->noiseStrength/-2, this->noiseStrength/2);
        new_thetas.push_back(avg_theta);
    }

    // Updating the direction and position of the particle
    int count = 0;
    for (Particle &current_particle: this->particles){
        current_particle.x += std::cos(new_thetas[count])*current_particle.v*this->timeStep;
        current_particle.y += std::sin(new_thetas[count])*current_particle.v*this->timeStep;
        current_particle.theta = new_thetas[count];
        count++; 
    }
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