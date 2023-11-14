#ifndef LIGHTSTUBIMPL_HPP
#define LIGHTSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/LightStatusStubDefault.hpp>

class LightStubImpl : public v1_0::commonapi:: LightStatusStubDefault {
public:
    LightStubImpl();
    ~LightStubImpl();
};

#endif
