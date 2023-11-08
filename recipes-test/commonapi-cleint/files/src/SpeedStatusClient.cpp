#include "SpeedStatusClient.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

SpeedStatusClient::SpeedStatusClient() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string speed_instance = "commonapi.Speed";
    std::string connection = "client-sample";

    speedProxy_ = runtime->buildProxy<SpeedStatusProxy>(domain, speed_instance, connection);

    std::cout << "Successfully Speed Constructure" << std::endl;
}

void SpeedStatusClient::run() {

    std::cout << "Waiting for GearSelection service to become available." << std::endl;

    speedProxy_->getSpeedAttribute().getChangedEvent().subscribe(
        [&](const float& speed){std::cout << "IC Speed: " << speed << std::endl;}
    );

}

