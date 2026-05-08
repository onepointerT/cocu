// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cursor_position.hpp"
#include "whatisthere_plugin.hpp"


#include "jsonvariant.hpp"


namespace cocu {

class WhatIsThis {
public:
    typedef typename dscpp::json::JsonValue result_t;
    typedef result_t& (*whatIsAtThisPos_f)(const cocu::DesktopPoint& where);

    static whatIsAtThisPos_f whatIsAtThisPos;
};

} // namespace cocu
