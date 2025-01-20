#ifndef PARTICLE_H
#define PARTICLE_H

class Particle{
    public:
    // elements of Particle class
        double x; //x coordinate
        double y; //y coordinate
        double theta; //angle
        double v; //magnitude of velocity
        double r; //radius of interaction

    //default constructor
        Particle();
};

#endif