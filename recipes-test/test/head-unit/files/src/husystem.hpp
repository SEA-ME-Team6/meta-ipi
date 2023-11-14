#ifndef HEADUNITSYSTEM_HPP
#define HEADUNITSYSTEM_HPP

#include <memory>
#include <QObject>
#include <stdint.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/RPMStatusProxy.hpp>
#include <v1/commonapi/LightStatusProxy.hpp>

using namespace v1::commonapi;

class HUSystem: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool light READ getLight NOTIFY lightChanged)

public:
    HUSystem();
    bool getLight() const;

public slots:
    void changegear(quint8 gearselect);

signals:
    void lightChanged();

private:

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<RPMStatusProxy<>> rpmProxy;
    std::shared_ptr<LightStatusProxy<>> lightProxy;

    float rpm_check;
    bool light;
};

#endif // GEARCLIENT_HPP
