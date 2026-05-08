// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_predictional.hpp"
#include "cocu_metagraph.hpp"
#include "desktopcontext.hpp"
#include "cocu_rest.hpp"

namespace cocu {


template< class ClientLibPluginProviderT >
class MetaDesktop
    :   public ContextPlugin
    ,   public DesktopContext
    ,   public ReST_Transmitter< ClientLibPluginProviderT >
{};

} // namespace cocu
