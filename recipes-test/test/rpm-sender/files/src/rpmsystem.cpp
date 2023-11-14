#include "rpmsystem.hpp"

#include <iostream>
#include <thread>

RPMSystem::RPMSystem() {
    runtime = CommonAPI::Runtime::get();
    rpmservice = std::make_shared<RPMStubImpl>();

    std::string domain = "local";
    std::string rpm_instance = "RPMStatus";
    std::string rpm_connection = "service-rpm";

    while (!runtime->registerService(domain, rpm_instance, rpmservice, rpm_connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully RPM Registered Service!" << std::endl;
}

void RPMSystem::setRPM(float rpm) {
    rpmservice->setRpmAttribute(rpm);
}
