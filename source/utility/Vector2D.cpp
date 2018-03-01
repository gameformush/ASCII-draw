//
// Created by myst on 2/26/18.
//

#include "Vector2D.h"

int ASCII_Draw::Vector2D::getX() const {
    return x;
}

void ASCII_Draw::Vector2D::setX(int x) {
    Vector2D::x = x;
}

int ASCII_Draw::Vector2D::getY() const {
    return y;
}

void ASCII_Draw::Vector2D::setY(int y) {
    Vector2D::y = y;
}

ASCII_Draw::Vector2D::Vector2D(const ASCII_Draw::Vector2D &other) {
    this->x = other.getX();
    this->y = other.getY();
}
