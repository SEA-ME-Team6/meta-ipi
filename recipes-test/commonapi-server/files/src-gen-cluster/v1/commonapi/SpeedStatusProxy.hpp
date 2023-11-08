/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Speed_Status_PROXY_HPP_
#define V1_COMMONAPI_Speed_Status_PROXY_HPP_

#include <v1/commonapi/SpeedStatusProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/AttributeExtension.hpp>
#include <CommonAPI/Factory.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename ... _AttributeExtensions>
class SpeedStatusProxy
    : virtual public SpeedStatus,
      virtual public SpeedStatusProxyBase,
      virtual public _AttributeExtensions... {
public:
    SpeedStatusProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~SpeedStatusProxy();

    typedef SpeedStatus InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Returns the wrapper class that provides access to the attribute speed.
     */
    virtual SpeedAttribute& getSpeedAttribute() {
        return delegate_->getSpeedAttribute();
    }



 private:
    std::shared_ptr< SpeedStatusProxyBase> delegate_;
};

typedef SpeedStatusProxy<> SpeedStatusProxyDefault;

namespace SpeedStatusExtensions {
    template <template <typename > class _ExtensionType>
    class SpeedAttributeExtension {
     public:
        typedef _ExtensionType< SpeedStatusProxyBase::SpeedAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension< SpeedStatusProxyBase::SpeedAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        SpeedAttributeExtension(SpeedStatusProxyBase& proxy): attributeExtension_(proxy.getSpeedAttribute()) {
        }
    
        inline extension_type& getSpeedAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

} // namespace SpeedStatusExtensions

//
// SpeedStatusProxy Implementation
//
template <typename ... _AttributeExtensions>
SpeedStatusProxy<_AttributeExtensions...>::SpeedStatusProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< SpeedStatusProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< SpeedStatusProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
SpeedStatusProxy<_AttributeExtensions...>::~SpeedStatusProxy() {
}


template <typename ... _AttributeExtensions>
const CommonAPI::Address &SpeedStatusProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool SpeedStatusProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool SpeedStatusProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& SpeedStatusProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& SpeedStatusProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> SpeedStatusProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace commonapi
} // namespace v1

namespace CommonAPI {
template<template<typename > class _AttributeExtension>
struct DefaultAttributeProxyHelper< ::v1::commonapi::SpeedStatusProxy,
    _AttributeExtension> {
    typedef typename ::v1::commonapi::SpeedStatusProxy<
            ::v1::commonapi::SpeedStatusExtensions::SpeedAttributeExtension<_AttributeExtension>
    > class_t;
};
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Speed_Status_PROXY_HPP_
