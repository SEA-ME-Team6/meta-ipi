/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_RPM_Status_STUB_HPP_
#define V1_COMMONAPI_RPM_Status_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/RPMStatus.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service RPMStatus. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class RPMStatusStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual RPMStatus {
 public:
    ///Notifies all remote listeners about a change of value of the attribute rpm.
    virtual void fireRpmAttributeChanged(const float &rpm) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockRpmAttribute(bool _lockAccess) {
        if (_lockAccess) {
            rpmMutex_.lock();
        } else {
            rpmMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex rpmMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for RPMStatus.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class RPMStatusStubRemoteEvent
{
public:
    virtual ~RPMStatusStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute rpm
    virtual bool onRemoteSetRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, float _value) = 0;
    /// Action callback for remote set requests on the attribute rpm
    virtual void onRemoteRpmAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service RPMStatus to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class RPMStatusStub
    : public virtual CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>
{
public:

    virtual ~RPMStatusStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute rpm
    virtual const float &getRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireRpmAttributeChanged(float _value) {
    auto stubAdapter = CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireRpmAttributeChanged(_value);
    }
    void lockRpmAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockRpmAttribute(_lockAccess);
    }


    using CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<RPMStatusStubAdapter, RPMStatusStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef RPMStatusStubRemoteEvent RemoteEventType;
    typedef RPMStatus StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_RPM_Status_STUB_HPP_