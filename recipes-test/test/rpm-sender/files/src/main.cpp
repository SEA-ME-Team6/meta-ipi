#include "canreceive.hpp"
#include "rpmsystem.hpp"
#include <iostream>

int main() {
    CanReceive receiver("can0");
    RPMSystem rpmsystem;

    while (true) {
        float rpm = receiver.getRpm();
        rpmsystem.setRPM(rpm);
    }
    return 0;
}
