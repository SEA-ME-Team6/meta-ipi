#ifndef SPEEDSTUBIMP_HPP
#define SPEEDSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusStubDefault.hpp>


class SpeedStubImpl : public v1_0::commonapi:: SpeedStatusStubDefault {
public:
    SpeedStubImpl();
    ~SpeedStubImpl();
};

#endif


