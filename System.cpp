#ifndef SYSTEM_H
#define SYTEM_H

#include <vector> //standard C++ vectors
#include "box.h" // To be Created
#include "particle.h" // To be Created

class System{
    public:
    System();
    int particleNumber;
    double noiseStrength;
    Box simulationBox;
    std::vector<Particle> particles;

    void updateRule()
}

#endif