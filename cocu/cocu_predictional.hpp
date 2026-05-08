// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_actioncallback.hpp"
#include "cocu_apiplugin.hpp"
#include "cocu_metagraph.hpp"

#include <stack>

#include "jsonobject.hpp"

namespace cocu {
namespace predictional {

class Predictional
    :   public cocu::plugin::ApiAdaption
    ,   public cocu::meta::Action
{
public:
    typedef typename meta::Node<> cocu_node_t;

    std::stack< cocu_node_t* > reference_nodes;
};


class PredictionCombination
    :   
{};


} // namespace predictional


using Predictional = predictional::Predictional;

} // namespace cocu
