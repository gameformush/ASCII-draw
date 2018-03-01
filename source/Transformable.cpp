//
// Created by myst on 3/1/18.
//

#include "Transformable.h"

void ASCII_Draw::Transformable::scale(std::pair<double, double> &factor) {
    tm_container tmp;
    tmp[0] = {factor.first, 0, 0};
    tmp[1] = {0, factor.second, 0};
    tmp[2] = {0, 0, 1};
    transform_matrix.append_transform(tmp);
}

void ASCII_Draw::Transformable::rotate(double rad) {
    tm_container s_scale;
    s_scale[0] = {cos(rad), - sin(rad), 0};
    s_scale[1] = {sin(rad), cos(rad), 0};
    s_scale[2] = {0, 0, 1};
    transform_matrix.append_transform(s_scale);
}

void ASCII_Draw::Transformable::translate(ASCII_Draw::Vector2D & shift) {
    tm_container tmp;
    tmp[0] = {1, 0, shift.getX()};
    tmp[1] = {0, 1, shift.getY()};
    tmp[2] = {0, 0, 1};
    transform_matrix.append_transform(tmp);
}

void ASCII_Draw::Transformable::transform(ASCII_Draw::Transform_matrix & tm) {

    transform_matrix.append_transform(tm);
}

void ASCII_Draw::Transformable::set_transformation(ASCII_Draw::Transform_matrix & tm) {
    transform_matrix = Transform_matrix(tm);
}

void ASCII_Draw::Transformable::skew(double ax, double ay) {
    tm_container tmp;
    tmp[0] = {1, tan(ax), 0};
    tmp[1] = {tan(ay), 1, 0};
    tmp[2] = {0, 0, 1};
    transform_matrix.append_transform(tmp);
}

ASCII_Draw::Transform_matrix ASCII_Draw::Transformable::get_matrix() {
    return transform_matrix;
}

std::pair<int, int> ASCII_Draw::Transformable::transfrom_point(const std::pair<int, int> & p) {
    return transform_matrix.transfrom_point(p);
}