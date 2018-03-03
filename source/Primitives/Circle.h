//
// Created by myst on 2/27/18.
//

#ifndef ASCII_DRAW_CIRCLE_H
#define ASCII_DRAW_CIRCLE_H

#include "Base_component.h"

namespace ASCII_Draw {

    class Circle: public ASCII_Draw::Base_component {
    private:
        unsigned int radius;
    protected:
        void _render();
    public:
        Circle(Vector2D, unsigned int);
        void setRadius(int);
    };
}


#endif //ASCII_DRAW_CIRCLE_H
