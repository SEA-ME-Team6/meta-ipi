#include "gamepad.h"
#include "gamepadsystem.hpp"
#include <unistd.h>

int main() {
    Gamepad* gamepad;
    GamepadSystem* gamepadsystem = new GamepadSystem;

    float steering = 0;
    float throttle = 0;
    bool light = true;
    
    while(true){
        gamepad->read_data(); 
    
        steering = gamepad->get_inputLX(); 
        throttle = gamepad->get_inputRY();
        light = gamepad->get_inputBY();
        // steering +=1;
        // throttle +=1;
        // light = !light;

        std::cout << "Steering: " << steering << std::endl;
        std::cout << "Throttle: " << throttle << std::endl;
        std::cout << "Light: " << light << std::endl;

        gamepadsystem->setSteeringAttribute(steering);
        gamepadsystem->setThrottleAttribute(throttle);
        gamepadsystem->setLightAttribute(light);

        sleep(1);
    }
    
    return 0;
}
