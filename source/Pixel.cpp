//
// Created by myst on 2/26/18.
//

#include "Pixel.h"

namespace ASCII_Draw
{
    Pixel::Pixel(std::string content,
                 unsigned short background,
                 unsigned short foreground,
                 bool bold,
                 bool underline,
                 bool reversed ) {
        this->style = Style(background,
                            foreground,
                            bold,
                            underline,
                            reversed);
        this->content = content;
    }

    std::string Pixel::getContent() const {
        return content;
    }

    void Pixel::setContent(std::string content) {
        this->content = content;
    }

    const Style &Pixel::getStyle() const {
        return style;
    }

    void Pixel::setStyle(const Style &style) {
        this->style = style;
    }

    Pixel::Pixel(const Pixel &other) {
        this->style = Style(other.style);
        this->content = other.content;
    }
}
