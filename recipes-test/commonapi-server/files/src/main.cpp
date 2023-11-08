#include "SpeedStatusServer.hpp"
#include <iostream>
#include <unistd.h>

int main() {
    SpeedStatusServer speed_server;
    //RPMServer rpm_server();

    float speed = 0.0;

    while (true) {
        speed_server.run(speed);
        speed += 1.0;
        sleep(1);
    }

    return 0;
}
