#include "box.h"

Box::Box(){

}

Box::Box(double lx, double ly, double x0, double y0){
    this->sidex = lx;
    this->sidey = ly;
    this->x0 = x0;
    this->y0 = y0;
}

void Box::setSides(double lx, double ly){
    this->sidex = lx;
    this->sidey = ly;
}

void Box::setOrigin(double x0, double y0){
    this->x0 = x0;
    this->y0 = y0;
}

double Box::getSidex(){
    return(sidex);
}

double Box::getSidey(){
    return(sidey);
}