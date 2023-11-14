#ifndef BATTERYSTUBIMPL_HPP
#define BATTERYSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/BatteryStatusStubDefault.hpp>

class BatteryStubImpl : public v1_0::commonapi:: BatteryStatusStubDefault {
public:
    BatteryStubImpl();
    ~BatteryStubImpl();
};

#endif


