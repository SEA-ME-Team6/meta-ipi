
#include <unistd.h>
#include "SpeedStatusClient.hpp"
#include <iostream>

int main() {

    SpeedStatusClient *speedclient = new SpeedStatusClient();

    while(true){
        speedclient->run();
        sleep(10000);
    }

    

    return 0;
}