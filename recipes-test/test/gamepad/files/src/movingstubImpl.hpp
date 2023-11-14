#ifndef MOVINGSTUBIMPL_HPP
#define MOVINGSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/MovingStatusStubDefault.hpp>

class MovingStubImpl : public v1_0::commonapi:: MovingStatusStubDefault {
public:
    MovingStubImpl();
    ~MovingStubImpl();
};

#endif
