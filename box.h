#ifndef BOX_H
#define BOX_H

class Box{
    private:
        double sidex;
        double sidey;
        double x0;
        double y0;
    public:
        Box();// default constructor with no parameters
        Box(double lx, double ly, double x0, double y0);// parameterised constructor

        // Functions for only setting sides or origin
        void setSides(double lx, double ly);
        void setOrigin(double x, double y);

        // Functions for accessing the values stored in private variables
        double getSidex();
        double getSidey();

};

#endif