//
// Created by myst on 2/26/18.
//

#include "Style.h"

namespace ASCII_Draw
{
    Style::Style(const Style & other)
    {
        this->background = other.background;
        this->foreground = other.foreground;
        this->bold = other.bold;
        this->underline = other.underline;
        this->reversed = other.reversed;
    }
    Style::Style(unsigned short background,
          unsigned short foreground,
          bool bold,
          bool underline,
          bool reversed)
    {
        ASCII_encoder encoder;
        this->background = encoder.background(background);
        this->foreground = encoder.foreground(foreground);
        this->bold = bold ? encoder.bold() : "";
        this->underline = underline ? encoder.underline() : "";
        this->reversed = reversed ? encoder.reverse() : "";
    }
}