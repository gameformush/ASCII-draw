//
// Created by myst on 2/26/18.
//
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#ifndef ASCII_DRAW_LAYER2D_H
#define ASCII_DRAW_LAYER2D_H

namespace ASCII_Draw {
    class Layer2D {
    private:
        std::vector<std::string> buffer;
        unsigned int height;
        unsigned int width;
    public:
        unsigned int getHeight() const;

        void setHeight(unsigned int height);

        unsigned int getWidth() const;

        void setWidth(unsigned int width);

        void resize(unsigned int, unsigned int);

        std::string &operator[](const std::pair<int, int>& );
        Layer2D(unsigned int width, unsigned int height);

    };

}

#endif //ASCII_DRAW_LAYER2D_H
