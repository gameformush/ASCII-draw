//
// Created by myst on 3/3/18.
//

#ifndef ASCII_DRAW_BEZIER_CURVE_H
#define ASCII_DRAW_BEZIER_CURVE_H

#include <array>
#include "../utility/Vector2D.h"
#include "Base_component.h"

namespace ASCII_Draw {
    class Bezier_curve: public Base_component {
    private:
        std::array<Vector2D, 3> pivot_points;
    protected:
        void _render();

    public:
        Bezier_curve(const Vector2D &, const Vector2D &, const Vector2D &);
        void set_points(const Vector2D &, const Vector2D &, const Vector2D &);

    };
}

#endif //ASCII_DRAW_BEZIER_CURVE_H
