//
// Created by myst on 2/26/18.
//

#include <algorithm>
#include <array>

#ifndef ASCII_DRAW_TRANSFORM_MATRIX_H
#define ASCII_DRAW_TRANSFORM_MATRIX_H

namespace  ASCII_Draw {
    typedef std::array<std::array<double, 3>, 3> tm_container;
    class Transform_matrix {
    private:
        tm_container transform;
    public:
        Transform_matrix(tm_container &);
        void append_transform(const Transform_matrix &);
        std::pair<int, int> transfrom_point(const std::pair<int, int> &);
        tm_container getMatrix() const;
    };
}

#endif //ASCII_DRAW_TRANSFORM_MATRIX_H
