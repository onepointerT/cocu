// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cursorroute.hpp"
#include "context_plugin.hpp"

#include "context.hpp"
#include "jsonobject.hpp"


namespace cocu {

class Context
    :   public dscpp::ctx::Context
    ,   public cocu::ContextPlugin
{
public:
    dscpp::json::JsonObject& data;
    cocu::CursorRoute& crs_route;
    bool clicked;
};

} // namespace cocu
