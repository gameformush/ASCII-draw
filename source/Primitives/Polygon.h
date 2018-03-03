//
// Created by myst on 3/1/18.
//

#ifndef ASCII_DRAW_POLYGON_H
#define ASCII_DRAW_POLYGON_H

#include <vector>
#include "Base_component.h"

namespace ASCII_Draw {
    class Polygon: public ASCII_Draw::Base_component {
    private:
        std::vector<Vector2D> path;
        bool closed;
    protected:
        void _render();
    public:
        Polygon(int, int, Vector2D);
        void close();
        void addPoint(const Vector2D &);
    };
}


#endif //ASCII_DRAW_POLYGON_H
