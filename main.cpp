#include<iostream>
#include "system.h"

int main(){
    System test(100, 20.0, 0.5, 0.1, 2025);
    test.randomStart();
    test.saveConfig("init.conf");
    return 0;
}
