// Copyright (C) 2026 OnePointer
//

#pragma once

#include <utility>

namespace cocu {

using Pixel = const unsigned int;


class DesktopPoint
    :   public std::pair< Pixel, Pixel >
{
public:
    typedef typename std::pair< Pixel, Pixel > (*getCurrentPixel_f)();

    static const getCurrentPixel_f getCurrentPixel;

    DesktopPoint( const std::pair< Pixel, Pixel >& current = DesktopPoint::getCurrentPixel() )
        :   std::pair< Pixel, Pixel >( current )
    {}
};

} // namespace cocu
