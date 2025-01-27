#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector> //to use standard C++ vectors
#include <random> //for the generator and uniform distribution
#include <cmath> // for pi value
#include <fstream> //for file saving
#include "box.h" //header for boxes
#include "particle.h" //header for particles

class System {
  public:
    System(int particleNumber, double sideLength, double timeStep,double noiseStrength, int seed);
    int   particleNumber;
    double noiseStrength;
    double sideLength;
    double timeStep;

    Box simulationBox;
    std::vector<Particle> particles;
    
    std::mt19937 gen;
    std::uniform_real_distribution<double> uniformDist;
    double uniform(double min, double max);

    void updateRule();
    void randomStart();  

    void saveConfig(const std::string &filename);
};

#endif
