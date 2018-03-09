//
// Created by myst on 2/26/18.
//

#include "Transform_matrix.h"

ASCII_Draw::tm_container ASCII_Draw::Transform_matrix::getMatrix() const {
    return transform;
}

std::pair<int, int> ASCII_Draw::Transform_matrix::transfrom_point(const std::pair<int, int> & point) const {
    std::vector<std::vector<int>> tmp(3, std::vector<int>(1, 0));
    tmp[0][0] = point.first;
    tmp[1][0] = point.second;
    tmp[2][0] = 1;

    int outer_left = transform.size(),
        inner_size = transform[0].size(),
        outer_right = 1;
    std::vector<double> new_container(3, 0);
    for (int row = 0; row < outer_left; ++row) {
        for (int col = 0; col < outer_right; ++col) {
            for (int inner = 0; inner < inner_size; ++inner) {
                new_container[row] += transform[row][inner] * tmp[inner][col];
            }
        }
    }

    return {(int)(new_container[0] + 0.5), (int)(new_container[1] + 0.5)};
}
// SHOULD CHANGE to proper matrix multiplication
void ASCII_Draw::Transform_matrix::append_transform(const ASCII_Draw::Transform_matrix &tm) {
    const tm_container matrix = tm.getMatrix();
    int outer_left = transform.size(),
        inner_size = transform[0].size(),
        outer_right = matrix.size();
    tm_container new_container {0};
    for (int row = 0; row < outer_left; ++row) {
        for (int col = 0; col < outer_right; ++col) {
            for (int inner = 0; inner < inner_size; ++inner) {
                new_container[row][col] += transform[row][inner] * matrix[inner][col];
            }
        }
    }
    transform = new_container;
}

ASCII_Draw::Transform_matrix::Transform_matrix(ASCII_Draw::tm_container & m) {
    transform = tm_container(m);
}

ASCII_Draw::Transform_matrix::Transform_matrix() {
    tm_container tmp;
    // default matrix -> point will not change
    tmp[0] = {1, 0, 0};
    tmp[1] = {0, 1, 0};
    tmp[2] = {0, 0, 1};
    transform = tmp;
}
