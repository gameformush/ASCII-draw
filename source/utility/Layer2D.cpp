//
// Created by myst on 2/26/18.
//

#include "Layer2D.h"

namespace ASCII_Draw
{
    Layer2D::Layer2D(unsigned int width, unsigned int height):width(width), height(height), buffer(width*height, "") {
        buffer.reserve(width*height);
    }

    unsigned int Layer2D::getHeight() const {
        return height;
    }

    void Layer2D::setHeight(unsigned int height) {
        this->height = height;
    }

    unsigned int Layer2D::getWidth() const {
        return width;
    }

    void Layer2D::setWidth(unsigned int width) {
        this->width = width;
    }

    std::string &Layer2D::operator[](const std::pair<int, int> & index) {
        unsigned int id = index.first + index.second * this->width;
        return buffer[id];
    }

    void Layer2D::resize(unsigned int w, unsigned int h) {
        this->width = w;
        this->height = h;
        buffer.resize(w * h);
        buffer.reserve(w * h);
    }
}
