#ifndef VEHICLESTATUSCLIENT_HPP
#define VEHICLESTATUSCLIENT_HPP

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/GearSelectionProxy.hpp>
#include <v1/commonapi/BatteryStatusProxy.hpp>

using namespace v1::commonapi;

class VehicleStatusClient : public QObject {
    Q_OBJECT
public:
    VehicleStatusClient();
    void run();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearSelectionProxy<>> gearProxy_;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy_;
    std::shared_ptr<BatteryStatusProxy<>> batteryProxy_;
};

#endif // SPEEDSTATUSCLIENT_H
