//
// Created by myst on 2/26/18.
//

#include "Pixel.h"
#include "Pixel_encoder.h"

namespace ASCII_Draw
{
    Pixel::Pixel() {
        this->background = RGB(0, 0, 0);
        this->foreground = RGB(255, 255, 255);
        this->bold = false;
        this->underline = false;
        this->reversed = false;
        this->transparent = false;
        this->content = " ";
    }

    Pixel::Pixel(std::string content,
                 const RGB &background,
                 const RGB &foreground,
                 bool bold,
                 bool underline,
                 bool reversed,
                 bool transparent) {
        this->background = background;
        this->foreground = foreground;
        this->bold = bold;
        this->underline = underline;
        this->reversed = reversed;
        this->transparent = transparent;
        this->content = content;
    }

    Pixel::Pixel(const Pixel &other) {
        this->background = other.background;
        this->foreground = other.foreground;
        this->bold = other.bold;
        this->underline = other.underline;
        this->reversed = other.reversed;
        this->transparent = other.transparent;
        this->content = other.content;
    }

    std::string Pixel::getContent() const {
        return content;
    }

    void Pixel::setContent(std::string content) {
        this->content = content;
    }

    const RGB &Pixel::getBackground() const {
        return background;
    }

    void Pixel::setBackground(const RGB &background) {
        Pixel::background = background;
    }

    const RGB &Pixel::getForeground() const {
        return foreground;
    }

    void Pixel::setForeground(const RGB &foreground) {
        Pixel::foreground = foreground;
    }

    bool Pixel::isBold() const {
        return bold;
    }

    void Pixel::setBold(bool bold) {
        Pixel::bold = bold;
    }

    bool Pixel::isUnderline() const {
        return underline;
    }

    void Pixel::setUnderline(bool underline) {
        Pixel::underline = underline;
    }

    bool Pixel::isReversed() const {
        return reversed;
    }

    void Pixel::setReversed(bool reversed) {
        Pixel::reversed = reversed;
    }

    std::ostringstream &operator<<(std::ostringstream &stream, const Pixel &pixel) {
        {
            pixel_encoder(pixel, stream);
            return stream;
        }
    }

    void Pixel::setTransparent(bool trans) {
        transparent = trans;
    }

    bool Pixel::isTransparent() const {
        return this->transparent;
    }
}
