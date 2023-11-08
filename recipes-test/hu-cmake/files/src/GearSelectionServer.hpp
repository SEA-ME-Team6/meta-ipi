#ifndef GEARSELECTIONSERVER_H
#define GEARSELECTIONSERVER_H

#include <CommonAPI/CommonAPI.hpp>
#include <QObject>
#include "GearSelectionStubImpl.hpp"

using namespace v1::commonapi;

class GearSelectionServer : public QObject {
    Q_OBJECT
public:
    GearSelectionServer();

public slots:
    void buttonPressed(int gearValue);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearSelectionStubImpl> service;
};


#endif


