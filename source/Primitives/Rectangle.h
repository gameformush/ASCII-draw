//
// Created by myst on 3/5/18.
//

#ifndef ASCII_DRAW_RECTANGLE_H
#define ASCII_DRAW_RECTANGLE_H


#include <vector>
#include "Base_component.h"
#include "Polygon.h"

namespace ASCII_Draw {
    class Rectangle: public ASCII_Draw::Base_component {
    private:
        Polygon helper;
    protected:
        void _render();
    public:
        Rectangle();
        Rectangle(int width , int height ,const Vector2D & position);
    };
}



#endif //ASCII_DRAW_RECTANGLE_H
