/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Light_Status_PROXY_BASE_HPP_
#define V1_COMMONAPI_Light_Status_PROXY_BASE_HPP_

#include <v1/commonapi/LightStatus.hpp>



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <CommonAPI/Attribute.hpp>
#include <CommonAPI/Proxy.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

class LightStatusProxyBase
    : virtual public CommonAPI::Proxy {
public:
    typedef CommonAPI::ObservableAttribute<bool> LightAttribute;


    virtual LightAttribute& getLightAttribute() = 0;

    virtual std::future<void> getCompletionFuture() = 0;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Light_Status_PROXY_BASE_HPP_
