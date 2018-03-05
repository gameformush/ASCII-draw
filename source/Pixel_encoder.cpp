//
// Created by myst on 2/26/18.
//

#include "Pixel_encoder.h"

namespace ASCII_Draw {

    void pixel_encoder(const ASCII_Draw::Pixel &pixel, std::ostringstream &stream) {
        if (pixel.isTransparent()) {
            stream << pixel.getContent().c_str();
            return;
        }
        stream << ASCII_encoder::background(ASCII_encoder::rgbTo256(pixel.getBackground())).c_str()
               << ASCII_encoder::foreground(ASCII_encoder::rgbTo256(pixel.getForeground())).c_str()
               << (pixel.isBold() ? ASCII_encoder::bold().c_str() : "")
               << (pixel.isReversed() ? ASCII_encoder::reverse().c_str() : "")
               << (pixel.isUnderline() ? ASCII_encoder::underline().c_str() : "")
               << pixel.getContent().c_str()
               << ASCII_encoder::reset().c_str();
    }
}