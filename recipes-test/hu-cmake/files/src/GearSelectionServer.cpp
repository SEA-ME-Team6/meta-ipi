#include "GearSelectionServer.hpp"

GearSelectionServer::GearSelectionServer() {
    CommonAPI::Runtime::setProperty("LogContext", "GS_S");
    CommonAPI::Runtime::setProperty("LogApplication", "GS_S");
    CommonAPI::Runtime::setProperty("LibraryBase", "GearSelection");

    runtime = CommonAPI::Runtime::get();
    service = std::make_shared<GearSelectionStubImpl>();

    std::string domain = "local";
    std::string instance = "commonapi.GearSelection";
    std::string connection = "service-sample";

    while (!runtime->registerService(domain, instance, service, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;
}


void GearSelectionServer::buttonPressed(int gearValue) {
    service->setGearAttribute(gearValue);
    std::cout << "HU gear: "<< gearValue << std::endl;

}

