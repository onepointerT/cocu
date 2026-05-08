// Copyright (C) 2026 OnePointer
//

#pragma once

#include "cocu_actioncallback.hpp"
#include "cocu_apiplugin.hpp"
#include "cocu_metatree.hpp"
#include "desktopcontext.hpp"

#include "graph.hpp"
#include "edge.hpp"


namespace cocu {
namespace meta {


template< class ContentT = cocu::MetaTree, typename numID = unsigned int >
class Edge
    :   public passenger::Edge< cocu::meta::ApiAbsolvent<numID>, cocu::meta::Action >
{};


template< class ContentT = cocu::MetaTree, class EdgeT = cocu::meta::Edge< ContentT >, typename numID = unsigned int >
class Node
    :   public passenger::PassengerNode< cocu::meta::ApiAbsolvent<numID>, EdgeT >
{};


template< class ContentT = cocu::MetaTree, class NodeT = cocu::meta::Node<ContentT> >
class Graph
    :   public passenger::Graph< NodeT >
{};


} // namespace meta
} // namespace cocu
