// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_actioncallback.hpp"
#include "cocu_apiplugin.hpp"

#include <stack>

#include "jsonobject.hpp"

namespace cocu {



class ReST_Plugin
    :   public cocu::plugin::ApiAdaption
{};



class ReST
    :   public dscpp::ctx::InformationContext
    ,   public std::stack< dscpp::json::JsonObject >
    ,   public ReST_Plugin
{};


template< class ClientLibPluginProviderT >
class ReST_Transmitter
    :   public cocu::plugin::PluginContext< ClientPluginProviderT, ReST_Plugin >
{};



} // namespace cocu
