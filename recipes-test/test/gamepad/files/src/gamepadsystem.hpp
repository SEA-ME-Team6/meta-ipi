#ifndef GAMEPADSYSTEM_HPP_
#define GAMEPADSYSTEM_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "movingstubImpl.hpp"
#include "lightstubImpl.hpp"


using namespace v1::commonapi;

class GamepadSystem {
public:
    GamepadSystem();
    void setSteeringAttribute(float steering);
    void setThrottleAttribute(float throttle);
    void setLightAttribute(bool light);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<MovingStubImpl> movingService;
    std::shared_ptr<LightStubImpl> lightService;
    
};

#endif 
