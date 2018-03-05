//
// Created by myst on 2/26/18.

//
#ifndef ASCII_DRAW_PIXEL_H
#define ASCII_DRAW_PIXEL_H
#include <iostream>
#include "utility/ASCII_encoding.cpp"
#include "utility/RGB.h"
#pragma once
/*
 * Definition of atomic "pixel" type for drawing
 */
namespace ASCII_Draw
{
    class Pixel
    {
    private:
        std::string content;
        RGB background;
        RGB foreground;
        bool bold;
        bool underline;
        bool reversed;
        bool transparent;
    public:
        Pixel();
        Pixel(std::string content,
              const RGB & background = RGB(0,0,0),
              const RGB & foreground = RGB(0,0,0),
              bool bold = false,
              bool underline = false,
              bool reversed = false,
              bool transparent = false
        );

        Pixel(const Pixel &other);
        friend std::ostringstream & operator <<(std::ostringstream &stream, const Pixel &pixel);

        std::string getContent() const;

        void setContent(std::string content);

        const RGB &getBackground() const;

        void setBackground(const RGB &background);

        const RGB &getForeground() const;

        void setForeground(const RGB &foreground);

        bool isBold() const;

        void setBold(bool bold);

        bool isUnderline() const;

        void setUnderline(bool underline);

        bool isReversed() const;

        void setReversed(bool reversed);

        void setTransparent(bool trans);

        bool isTransparent() const;
    };

    const Pixel Transparent(" ", RGB(0, 0, 0), RGB(0, 0, 0), false, false, false, true);
}

#endif //ASCII_DRAW_PIXEL_H
