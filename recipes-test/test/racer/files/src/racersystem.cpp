#include "racersystem.hpp"

#include <iostream>
#include <thread>

RacerSystem::RacerSystem() : current_battery(0), filtered_battery(0), prev_filtered_battery(0), alpha(0.3){
    runtime = CommonAPI::Runtime::get();
    std::string domain = "local";

    //battery stub
    batteryService = std::make_shared<BatteryStubImpl>();
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "service-battery";
    while (!runtime->registerService(domain, battery_instance, batteryService, battery_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battey Service!" << std::endl;

    //gear stub
    gearService = std::make_shared<GearStubImpl>(racer);
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "service-gear";
    while (!runtime->registerService(domain, gear_instance, gearService, gear_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Gear Service!" << std::endl;

    //moving proxy
    std::string moving_instance = "MovingStatus";
    std::string moving_connection = "service-moving";
    movingProxy = runtime->buildProxy<MovingStatusProxy>(domain, moving_instance, moving_connection);

    std::cout << "Waiting for Moving service to become available." << std::endl;
    movingProxy->getSteeringAttribute().getChangedEvent().subscribe(
        [&](const float& steering_){
            racer->set_steering_percent(steering_); 
        }
    );
    movingProxy->getThrottleAttribute().getChangedEvent().subscribe(
        [&](const float& throttle_){
            racer->set_throttle_percent(throttle_); 
        }
    );

    //ligth stub
    lightService = std::make_shared<LightStubImpl>();
    std::string light_from_racer_instance = "LightStatus_from_racer";
    std::string light_from_racer_connection = "service-light";
    while (!runtime->registerService(domain, light_from_racer_instance, lightService, light_from_racer_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Light Service!" << std::endl;

    //light proxy
    std::string light_from_game_instance = "LightStatus_from_gamepad";
    std::string light_from_game_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_from_game_instance, light_from_game_connection);

    std::cout << "Waiting for Light service to become available." << std::endl;
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            racer->setLight(light_); 
            bool currentlight = racer->getLight();
            lightService->setLightAttribute(currentlight);
        }
    );
}

void RacerSystem::setBattery(uint32_t batteryStatus) {
    std::cout << "Battery Voltage: " << batteryStatus << " V" << std::endl;
    batteryService->setBatteryAttribute(batteryStatus);
}

uint32_t RacerSystem::getBattery() {
    current_battery = racer->getBatttery(); 
    
    //filtering
    filtered_battery = alpha * current_battery + (1 - alpha) * prev_filtered_battery;
    prev_filtered_battery = filtered_battery;
    return filtered_battery;
}