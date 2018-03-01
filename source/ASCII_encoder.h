//
// Created by myst on 2/26/18.
//
#include <string>
#include "utility/ASCII_encoding.cpp"

#ifndef ASCII_DRAW_STYLE_ENCODING_H
#define ASCII_DRAW_STYLE_ENCODING_H

/*
 * Style encoder implements ASCII encoding to meaningful components of type encoded_style
 * composed from some ASCII encoding pieces
 */

namespace ASCII_Draw
{
    // interface of creating encoded style
    typedef std::string encoded_style;

    struct ASCII_encoder
    {
        encoded_style background(unsigned short code) const
        {
            return _ESCAPE_SEQ + _BG + std::to_string(code) + _CLOSER;
        }
        encoded_style foreground(unsigned short code) const
        {
            return _ESCAPE_SEQ + _FG + std::to_string(code) + _CLOSER;
        }
        encoded_style bold() const
        {
            return _ESCAPE_SEQ + _BOLD + _CLOSER;
        }
        encoded_style underline() const
        {
            return _ESCAPE_SEQ + _UNDERLINE + _CLOSER;
        }
        encoded_style reverse() const
        {
            return _ESCAPE_SEQ + _REVERSE + _CLOSER;
        }
        encoded_style move_up(unsigned int units)
        {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_UP;
        }
        encoded_style move_left(unsigned int units)
        {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_LEFT;
        }
        encoded_style clear_all()
        {
            return _ESCAPE_SEQ + _CLEAR_ALL;
        }
        encoded_style reset()
        {
            return _ESCAPE_SEQ + _RESET;
        }
    };
}

#endif //ASCII_DRAW_STYLE_ENCODING_H
