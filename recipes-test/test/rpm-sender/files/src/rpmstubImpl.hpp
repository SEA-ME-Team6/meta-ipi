#ifndef RPMSTUBIMP_HPP
#define RPMSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/RPMStatusStubDefault.hpp>


class RPMStubImpl : public v1_0::commonapi:: RPMStatusStubDefault {
public:
    RPMStubImpl();
    ~RPMStubImpl();
};

#endif


