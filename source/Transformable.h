//
// Created by myst on 3/1/18.
//

#ifndef ASCII_DRAW_TRANSFORMABLE_H
#define ASCII_DRAW_TRANSFORMABLE_H

#include "./utility/Vector2D.h"
#include "./utility/Transform_matrix.h"


namespace ASCII_Draw {
    class Transformable {
    private:
        ASCII_Draw::Transform_matrix transform_matrix;
    public:
        void scale(std::pair<double, double> &factor);
        void rotate(double rad = 0);
        void translate(ASCII_Draw::Vector2D &);
        void transform(ASCII_Draw::Transform_matrix &);
        void set_transformation(ASCII_Draw::Transform_matrix &);
        void skew(double ax =0, double ay = 0);
        std::pair<int, int> transfrom_point(const std::pair<int, int> &);
        ASCII_Draw::Transform_matrix get_matrix();
    };
}

#endif //ASCII_DRAW_TRANSFORMABLE_H
