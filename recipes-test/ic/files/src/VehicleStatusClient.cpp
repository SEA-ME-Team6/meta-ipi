#include "VehicleStatusClient.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

VehicleStatusClient::VehicleStatusClient() {
    CommonAPI::Runtime::setProperty("LogContext", "VS_C");
    CommonAPI::Runtime::setProperty("LogApplication", "VS_C");
    CommonAPI::Runtime::setProperty("LibraryBase", "GearSelection");

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    std::string Gear_instance = "commonapi.Gear";
    std::string Speed_instance = "commonapi.Speed";
    std::string Battery_instance = "commonapi.Battery";

    std::string connection = "client-gear";

    gearProxy_ = runtime->buildProxy<GearSelectionProxy>(domain, Gear_instance, connection);
    speedProxy_ = runtime->buildProxy<SpeedStatusProxy>(domain, Speed_instance, connection);
    batteryProxy_ = runtime->buildProxy<BatteryStatusProxy>(domain, Battery_instance, connection);
}

void VehicleStatusClient::run() {

    std::cout << "Waiting for GearSelection service to become available." << std::endl;
    /*
    while (!gearProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "ahahah" << std::endl;
    }

    std::cout << "Waiting for SpeedStatus service to become available." << std::endl;
    while (!speedProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << "Waiting for BatteryStatus service to become available." << std::endl;
    while (!batteryProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    */

    gearProxy_->getGearAttribute().getChangedEvent().subscribe(
        [&](const int32_t& gear){std::cout << "IC Gear: " << gear << std::endl;}
    );

    speedProxy_->getSpeedAttribute().getChangedEvent().subscribe(
        [&](const float& speed){std::cout << "IC Speed: " << speed << std::endl;}
    );
    
    
    batteryProxy_->getBatteryAttribute().getChangedEvent().subscribe(
        [&](const int32_t& battery){std::cout << "IC Battery: " <<battery << std::endl;}
    );
    

}

