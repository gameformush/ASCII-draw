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
        Polygon();
        Polygon(int, int,const Vector2D &);
        void close();
        const std::vector<ASCII_Draw::Vector2D> & getPath() const;
        void setPath(const std::vector<ASCII_Draw::Vector2D> & path);
        bool isClosed();
        void addPoint(const Vector2D &);
    };
}


#endif //ASCII_DRAW_POLYGON_H
