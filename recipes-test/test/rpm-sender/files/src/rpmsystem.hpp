#ifndef RPMSYSTEM_HPP_
#define RPMSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "rpmstubImpl.hpp"

using namespace v1::commonapi;

class RPMSystem {
public:
    RPMSystem();
    void setRPM(float rpm);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<RPMStubImpl> rpmservice;
    
};

#endif 
