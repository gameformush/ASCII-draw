//
// Created by myst on 2/26/18.
//

#ifndef ASCII_DRAW_PIXEL_H
#define ASCII_DRAW_PIXEL_H

#include <iostream>
#include "utility/ASCII_encoding.cpp"
#include "utility/RGB.h"

/*
 * Definition of atomic "pixel" type for drawing
 * Pixel store information about its drawing properties.
 * Transparent prop - not exactly transparent, transparency in this library
 * mean that ONLY content will be drawn other properties will be ignored
 * If really transparent pixel required use predefined Transparent below
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

        bool operator ==(const Pixel & rhs) const;
        // getters & setters

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

    // TRULY transparent pixel
    const Pixel Transparent(" ", RGB(0, 0, 0), RGB(0, 0, 0), false, false, false, true);
}

#endif //ASCII_DRAW_PIXEL_H
