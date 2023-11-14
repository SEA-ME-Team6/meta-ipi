#include "gearstubImpl.hpp"


GearStubImpl::GearStubImpl(Racer* racer) : racer(racer) {

}

void GearStubImpl::gearselection(const std::shared_ptr<CommonAPI::ClientId> _client,
                                 uint8_t _gearselect,
                                 gearselectionReply_t _reply) {
    racer->setGear(_gearselect);
    uint8_t currentGear = racer->getGear();
    setGearAttribute(currentGear);
    _reply(currentGear);
}