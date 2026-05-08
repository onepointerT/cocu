// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_actioncallback.hpp"
#include "desktopcontext.hpp"

#include "tree.hpp"


namespace cocu {
namespace meta {


template< class ContentT >
class Tree
    :   public passenger::Tree< ContentT, cocu::meta::Action >
{};


} // namespace meta

using MetaTree = cocu::meta::Tree< cocu::DesktopContext >;

} // namespace cocu
