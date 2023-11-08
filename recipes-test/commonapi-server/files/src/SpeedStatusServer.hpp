#ifndef SpeedStatusServer_HPP_
#define SpeedStatusServer_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "SpeedStubImpl.hpp"

using namespace v1::commonapi;

class SpeedStatusServer {
public:
    SpeedStatusServer();
    void run(float speed);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStubImpl> myService_;
    
};

#endif 
