//
// Created by myst on 3/1/18.
//

#ifndef ASCII_DRAW_TRANSFORMABLE_H
#define ASCII_DRAW_TRANSFORMABLE_H

#include "./utility/Vector2D.h"
#include "./utility/Transform_matrix.h"


/*
 * <Interface> class provide common 2d transformation interface
 *
 */

namespace ASCII_Draw {
    class Transformable {
    private:
        ASCII_Draw::Transform_matrix transform_matrix;
    public:
        Transformable();
        Transformable(const Transform_matrix & tm);
        virtual void scale(const std::pair<double, double> &factor);
        virtual void rotate(double rad = 0);
        virtual void translate(const Vector2D &);
        virtual void transform(const Transform_matrix &);
        virtual void set_transformation(const Transform_matrix &);
        virtual void skew(double ax =0, double ay = 0);
        virtual void reset();
        std::pair<int, int> transfrom_point(const std::pair<int, int> &);
        const ASCII_Draw::Transform_matrix & get_matrix() const;
    };
}

#endif //ASCII_DRAW_TRANSFORMABLE_H
