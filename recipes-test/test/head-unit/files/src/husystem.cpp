#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "husystem.hpp"

using namespace v1::commonapi;

HUSystem::HUSystem() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";

    //gear client
    std::string gear_instance = "GearStatus";
    std::string gear_connection = "client-gear";
    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, gear_instance, gear_connection);
    std::cout << "Waiting for GearSelection service to become available." << std::endl;

    //rpm client
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "client-rpm";
    rpmProxy = runtime->buildProxy<RPMStatusProxy>(domain, rpm_instance, rpm_connection);
    std::cout << "Waiting for Speed service to become available." << std::endl;
    rpmProxy->getRpmAttribute().getChangedEvent().subscribe(
        [&](const float& rpm_){
            rpm_check = rpm_;
        }
    );
    
    //light client
    std::string light_from_racer_instance = "LightStatus_from_racer";
    std::string light_from_racer_connection = "client-light";
    lightProxy = runtime->buildProxy<LightStatusProxy>(domain, light_from_racer_instance, light_from_racer_connection);
    std::cout << "Waiting for Light service to become available." << std::endl;
    lightProxy->getLightAttribute().getChangedEvent().subscribe(
        [&](const bool& light_){
            light = light_;
            emit lightChanged();
        }
    );

}
void HUSystem::changegear(quint8 gearselect){
    CommonAPI::CallStatus callStatus;
    uint8_t returnedGear;

    if(rpm_check < 5) {
        gearProxy->gearselection(gearselect, callStatus, returnedGear);
        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
            std::cout << "Gear set successfully. Returned gear: " << (int)returnedGear <<std::endl;
        } else {
            std::cout << "Failed to set gear." << std::endl;
        }
    }
}

bool HUSystem::getLight() const {
    std::cout << "HU Light: " << light << std::endl;
    return light;
}