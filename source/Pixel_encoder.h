//
// Created by myst on 2/26/18.
//

#ifndef ASCII_DRAW_STYLE_H
#define ASCII_DRAW_STYLE_H

#include "ASCII_encoder.h"
#include "Pixel.h"
#include <iostream>
#include <sstream>


namespace ASCII_Draw
{
    void pixel_encoder(const Pixel & pixel, std::ostringstream &stream );
}

#endif //ASCII_DRAW_STYLE_H
