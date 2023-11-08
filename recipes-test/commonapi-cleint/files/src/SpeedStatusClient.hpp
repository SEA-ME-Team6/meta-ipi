#ifndef SPEEDSTATUSCLIENT_HPP
#define SPEEDSTATUSCLIENT_HPP

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>

using namespace v1::commonapi;

class SpeedStatusClient {
public:
    SpeedStatusClient();
    void run();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy_;
};

#endif // SPEEDSTATUSCLIENT_HPP
