//
// Created by myst on 2/26/18.
//

#include "Style.h"
#include <iostream>
#include "utility/ASCII_encoding.cpp"

#ifndef ASCII_DRAW_PIXEL_H
#define ASCII_DRAW_PIXEL_H
#pragma once
/*
 * Definition of atomic "pixel" type for drawing
 */
namespace ASCII_Draw
{
    class Pixel
    {
    private:
        Style style;
    public:
        const Style &getStyle() const;

        void setStyle(const Style &style);

    private:
        std::string content;
    public:
        std::string getContent() const;

        void setContent(std::string content);

    public:
        Pixel(std::string content = " ",
              unsigned short background = 0,
              unsigned short foreground = 0,
              bool bold = false,
              bool underline = false,
              bool reversed = false
        );
        Pixel(const Pixel &other);
        friend std::ostringstream & operator <<(std::ostringstream &stream, const Pixel &pixel)
        {
            ASCII_Draw::ASCII_encoder encoder;
            stream << pixel.getStyle()
                   << pixel.getContent().c_str()
                   << encoder.reset();
            return stream;
        }
    };
}

#endif //ASCII_DRAW_PIXEL_H
