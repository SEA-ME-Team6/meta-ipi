#ifndef GEARSTUBIMPL_HPP
#define GEARSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusStubDefault.hpp>
#include "racer.h"

class GearStubImpl : public v1_0::commonapi:: GearStatusStubDefault {
private:
    Racer* racer;
public:
    GearStubImpl(Racer* racer);
    virtual void gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                               uint8_t _gearselect,
                               gearselectionReply_t _reply) override;
};

#endif


