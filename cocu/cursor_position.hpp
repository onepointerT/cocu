// Copyright (C) 2026 OnePointer
//

#pragma once

#include "desktoppoint.hpp"

#include "jsonvariant.hpp"


namespace cocu {

class CursorPosition
    :   public DesktopPoint
{
public:
    dscpp::json::JsonValue& here_data;
};

} // namespace cocu
