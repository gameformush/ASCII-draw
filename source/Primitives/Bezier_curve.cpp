//
// Created by myst on 3/3/18.
//

#include "Bezier_curve.h"

void ASCII_Draw::Bezier_curve::_render() {
    using namespace std;
    for (double t = 0, dx = 0.001; t <= 1; t += dx) {
        int x = (int)(((1 - t)* (1 - t)) * pivot_points[0].getX() +
                (1 - t) * 2 * t * pivot_points[1].getX() +
                t * t * pivot_points[2].getX() + 0.5);
        int y = (int)(((1 - t) * (1 - t)) * pivot_points[0].getY() +
                      (1 - t) * 2 * t * pivot_points[1].getY() +
                      t * t * pivot_points[2].getY() + 0.5);
        setPixel({x, y}, Pixel("x", 14, 127));
    }
}

ASCII_Draw::Bezier_curve::Bezier_curve(const ASCII_Draw::Vector2D & a, const ASCII_Draw::Vector2D & b,
                                       const ASCII_Draw::Vector2D & c) {
    pivot_points[0] = Vector2D(a);
    pivot_points[1] = Vector2D(b);
    pivot_points[2] = Vector2D(c);
    int width = std::max(a.getX(), std::max(b.getX(), c.getX()));
    int height = std::max(a.getY(), std::max(b.getY(), c.getY()));
    int x = std::min(a.getX(), std::min(b.getX(), c.getX()));
    int y = std::min(a.getY(), std::min(b.getY(), c.getY()));
    resize(width + 1, height + 1);
    setPosition(Vector2D({x ,y}));
}

void ASCII_Draw::Bezier_curve::set_points(const ASCII_Draw::Vector2D & a, const ASCII_Draw::Vector2D & b,
                                          const ASCII_Draw::Vector2D & c) {
    pivot_points[0] = Vector2D(a);
    pivot_points[1] = Vector2D(b);
    pivot_points[2] = Vector2D(c);
    update();
}
