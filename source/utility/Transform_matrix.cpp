//
// Created by myst on 2/26/18.
//

#include "Transform_matrix.h"

ASCII_Draw::tm_container ASCII_Draw::Transform_matrix::getMatrix() const {
    return transform;
}

std::pair<int, int> ASCII_Draw::Transform_matrix::transfrom_point(const std::pair<int, int> & point) {
    int x = 0, y = 0;
    std::vector<std::vector<int>> tmp(3, std::vector<int>(1, 0));
    tmp[0][0] = point.first;
    tmp[1][0] = point.second;
    tmp[2][0] = 1;

    int outer_left = transform.size(),
            inner = transform[0].size(),
            outer_right = 1;
    std::vector<int> new_container(3, 0);
    for (int i = 0; i < outer_left; ++i) {
        for (int j = 0, sum = 0; j < inner; ++j) {
            for (int k = 0; k < outer_right; ++k) {
                sum += transform[i][k] * tmp[j][k];
            }
            new_container[i] = sum;
            sum = 0;
        }
    }

    return {new_container[0], new_container[1]};
}
// SHOULD CHANGE to proper matrix multiplication
void ASCII_Draw::Transform_matrix::append_transform(const ASCII_Draw::Transform_matrix &tm) {
    const tm_container matrix = tm.getMatrix();
    int outer_left = transform.size(),
            inner = transform[0].size(),
            outer_right = matrix.size();
    tm_container new_container;
    for (int i = 0; i < outer_left; ++i) {
        for (int j = 0, sum = 0; j < inner; ++j) {
            for (int k = 0; k < outer_right; ++k) {
                sum += transform[i][k] * matrix[j][k];
            }
            new_container[i][j] = sum;
            sum = 0;
        }
    }
    transform = new_container;
}

ASCII_Draw::Transform_matrix::Transform_matrix(ASCII_Draw::tm_container & m) {
    transform = tm_container(m);
}
