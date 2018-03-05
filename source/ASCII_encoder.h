//
// Created by myst on 2/26/18.
//
#include <string>
#include "utility/ASCII_encoding.cpp"
#include "utility/RGB.h"

#ifndef ASCII_DRAW_STYLE_ENCODING_H
#define ASCII_DRAW_STYLE_ENCODING_H

/*
 * Pixel_encoder encoder implements ASCII encoding to meaningful components of type encoded_style
 * composed from some ASCII encoding pieces
 */

namespace ASCII_Draw
{
    // interface of creating encoded style
    typedef std::string encoded_style;
    namespace ASCII_encoder
    {
        encoded_style background(unsigned short code);
        encoded_style foreground(unsigned short code);
        encoded_style bold();
        encoded_style underline();
        encoded_style reverse();
        encoded_style saveCursor();
        encoded_style restoreCursor();
        encoded_style move_up(unsigned int units);
        encoded_style move_down(unsigned int utits);
        encoded_style move_left(unsigned int units);
        encoded_style move_right(unsigned int units);
        encoded_style clear_all();
        encoded_style reset();
        encoded_style hideCursor();
        encoded_style showCursor();
        unsigned short rgbTo256(const RGB & color);
    };
}

#endif //ASCII_DRAW_STYLE_ENCODING_H
