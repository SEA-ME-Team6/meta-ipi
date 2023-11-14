#include "gamepadsystem.hpp"
#include <iostream>
#include <thread>

GamepadSystem::GamepadSystem(){
    runtime = CommonAPI::Runtime::get();
    movingService = std::make_shared<MovingStubImpl>();
    lightService = std::make_shared<LightStubImpl>();

    std::string domain = "local";

    //moving stub
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    while (!runtime->registerService(domain, moving_instance, movingService, moving_connection)) {
        std::cout << "Register moving Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Moving Service!" << std::endl;

    // light stub
    std::string light_from_game_instance = "LightStatus_from_gamepad";
    std::string light_from_game_connection = "service-light";
    while (!runtime->registerService(domain, light_from_game_instance, lightService, light_from_game_connection)) {
        std::cout << "Register light Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Light Service!" << std::endl;

}

void GamepadSystem::setSteeringAttribute(float steering){
    movingService->setSteeringAttribute(steering);
}

void GamepadSystem::setThrottleAttribute(float throttle){
    movingService->setThrottleAttribute(throttle);
}

void GamepadSystem::setLightAttribute(bool light){
    lightService->setLightAttribute(light);
}