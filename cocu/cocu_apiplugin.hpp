// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_actioncallback.hpp"
#include "informationcontext.hpp"

#include <type_traits>

#include "action.hpp"
#include "graph_passenger.hpp"
#include "passenger.hpp"

namespace cocu {
namespace plugin {


/* Some interface virtual function preliminary to make an adaption work as plugin */
class ApiAdaption
    :   public passenger::ActionGroupFunction< passenger::GraphPassengerNumber<> >
    ,   public dscpp::ctx::InformationContext
{
public:
};

namespace meta {
template< typename numId = unsigned int >
class ApiAbsolvent
    :   public passenger::GraphPassengerNumber< passenger::PassengerNumber<numID> >
{};
} // namespace meta


template< class ExtendingClassT >
class ApiPlugin final
    :   public ApiAdaption
{
public:
    static ExtendingClassT& plugin;
};


template< class ClientLibAdaptionClassT, class CocuLibAdaptionClassT, class ContextProviderT = ApiPlugin< CocuLibAdaptionClassT > >
   /* requires std::is_base_of_v< ApiAdaption, ClientLibAdaptionClassT >
            & std::is_base_of_v< ApiAdaption, CocuLibAdaptionClassT >
            & std::is_base_of_v< ApiAdaption, ContextProviderT >*/
class PluginContext
{
protected:
    ContextProviderT& prov;
    ApiPlugin< ClientLibAdaptionClassT >& cli;

public:

};


} // namespace plugin
} // namespace cocu
