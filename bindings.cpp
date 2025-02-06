#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "system.h"   

PYBIND11_MODULE(myvicsek, m){
// module contents
    m.doc() = "MyVicsek: A Python binding for a C++ implementation of the Vicsek model"; 
    
    system_class.def(pybind11::init<int, double, double, double, int>(), 
                pybind11::arg("particleNumber"), 
                pybind11::arg("sideLength"), 
                pybind11::arg("timeStep"), 
                pybind11::arg("noiseStrength"), 
                pybind11::arg("seed"));
}