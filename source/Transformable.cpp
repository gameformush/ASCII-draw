//
// Created by myst on 3/1/18.
//

#include "Transformable.h"

void ASCII_Draw::Transformable::scale(double factor) {

}

void ASCII_Draw::Transformable::rotate(double rad) {

}

void ASCII_Draw::Transformable::translate(ASCII_Draw::Vector2D &) {

}

void ASCII_Draw::Transformable::transform(ASCII_Draw::Transform_matrix &) {

}

void ASCII_Draw::Transformable::set_transformation(ASCII_Draw::Transform_matrix &) {

}

void ASCII_Draw::Transformable::skew(double ax, double ay) {

}

ASCII_Draw::Transform_matrix ASCII_Draw::Transformable::get_matrix() {
    return ASCII_Draw::Transform_matrix();
}

std::pair<int, int> ASCII_Draw::Transformable::transfrom_point(const std::pair<int, int> &) {
    return std::pair<int, int>();
}
