//
// Created by myst on 2/26/18.
//

#include "ASCII_encoder.h"
#include <iostream>
#include <sstream>
#pragma once

#ifndef ASCII_DRAW_STYLE_H
#define ASCII_DRAW_STYLE_H

namespace ASCII_Draw
{
    struct Style
    {
        ASCII_Draw::encoded_style background;
        ASCII_Draw::encoded_style foreground;
        ASCII_Draw::encoded_style bold;
        ASCII_Draw::encoded_style underline;
        ASCII_Draw::encoded_style reversed;
        Style(unsigned short background = 0,
              unsigned short foreground = 0,
              bool bold = false,
              bool underline = false,
              bool reversed = false);
        Style(const Style & other);
        friend std::ostringstream&operator <<(std::ostringstream& stream, const Style& style)
        {
            stream << style.background.c_str()
                   << style.foreground.c_str()
                   << style.bold.c_str()
                   << style.underline.c_str()
                   << style.reversed.c_str();
            return stream;
        }
    };
}

#endif //ASCII_DRAW_STYLE_H
