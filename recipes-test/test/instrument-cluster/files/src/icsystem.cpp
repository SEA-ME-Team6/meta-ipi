#include "icsystem.hpp"
#include <iostream>
#include <thread>
# define M_PI           3.1415 /* pi */
# define WheelRadius    0.0325

using namespace v1::commonapi;

ICSystem::ICSystem() : speed(0), rpm(0), battery(0), gear(0) {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //rpm proxy
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "client-rpm";
    rpmProxy = runtime->buildProxy<RPMStatusProxy>(domain, rpm_instance, rpm_connection);

    std::cout << "Waiting for RPM service to become available." << std::endl;
    rpmProxy->getRpmAttribute().getChangedEvent().subscribe(
        [&](const float& rpm_){
            rpm = rpm_;
            convert_to_Speed(rpm);
            emit speedChanged();
            emit rpmChanged();
        }
    );

    //battery proxy
    std::string battery_instance = "BatteryStatus";
    std::string battery_connection = "client-battery";
    batteryProxy = runtime->buildProxy<BatteryStatusProxy>(domain, battery_instance, battery_connection);

    std::cout << "Waiting for Battery service to become available." << std::endl;
    batteryProxy->getBatteryAttribute().getChangedEvent().subscribe(
        [&](const uint32_t& battery_){
            battery = battery_;
            emit batteryChanged();
        }
    );

    //gear proxy
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);

    std::cout << "Waiting for GearSelection service to become available." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe(
        [&](const uint8_t& gear_){
            gear = gear_;
            emit gearChanged();
        }
    );

}

void ICSystem::convert_to_Speed(float rpm)  {
    speed = rpm * (2 * M_PI * WheelRadius);
}

float ICSystem::getSpeed() const {
    std::cout << "IC Speed: " << speed << std::endl;
    return speed;
}

float ICSystem::getRpm() const{
    std::cout << "IC Rpm: " << rpm << std::endl;
    return rpm;
}

uint32_t ICSystem::getBattery() const {
    std::cout << "IC Battery: " << battery << std::endl;
    return battery;
}

uint8_t ICSystem::getGear() const {
    std::cout << "IC Gear: " << (int)gear << std::endl;
    return gear;
}

