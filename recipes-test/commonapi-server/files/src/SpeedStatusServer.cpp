#include "SpeedStatusServer.hpp"
#include <typeinfo>
#include <iostream>
#include <thread>

SpeedStatusServer::SpeedStatusServer() {
    runtime = CommonAPI::Runtime::get();
    myService_ = std::make_shared<SpeedStubImpl>();

    std::string domain = "local";
    std::string instance = "commonapi.Speed";
    std::string connection = "service-sample";

    while (!runtime->registerService(domain, instance, myService_, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;
}

void SpeedStatusServer::run(float speed) {
    myService_->setSpeedAttribute(speed);
    std::cout << speed << std::endl;
}
