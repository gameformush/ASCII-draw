//
// Created by myst on 2/27/18.
//

#include "Circle.h"

ASCII_Draw::Circle::Circle(const ASCII_Draw::Vector2D & position, unsigned int radius):Base_component(2*radius , 2*radius, position) {
    this->radius = radius;
}

void ASCII_Draw::Circle::_render() {
    for(double dt = 0.01, t=0; t < 2* M_PI; t += dt)
    {
        int x = (int)round((radius-1)*cos(t) + (radius -1));
        int y = (int)round((radius -1)*sin(t) + (radius - 1));
        setPixel({x, y});
    }
}

void ASCII_Draw::Circle::setRadius(int radius) {
    if(radius <= 0) return;
    this->radius = (unsigned int)radius;
    unsigned int new_size = 2*this->radius;
    resize(new_size, new_size);
    clear_buffer();
    update();
}
