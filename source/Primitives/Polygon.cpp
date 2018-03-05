//
// Created by myst on 3/1/18.
//

#include <utility>
#include <source/Base_component.h>
#include "Polygon.h"

void ASCII_Draw::Polygon::_render() {
    for (int i = 0; i < path.size() - (closed ? 0 : 1) ; ++i) {
        for (double t = 0, dt = 0.001; t <= 1; t += dt) {
            int x = (int)(path[i].getX() + (path[closed && i == path.size() - 1 ? 0 : i + 1].getX()
                                            - path[i].getX()) * t + 0.5) - getPosition().getX();
            int y = (int)(path[i].getY() + (path[closed && i == path.size() - 1 ? 0 : i + 1].getY()
                                            - path[i].getY()) * t + 0.5) - getPosition().getY();
            setPixel({x ,y});
        }
    }
}

ASCII_Draw::Polygon::Polygon(int width, int height,const Vector2D &position):Base_component(width, height, position) {
    closed = false;
}

ASCII_Draw::Polygon::Polygon() {
    closed = false;
}

void ASCII_Draw::Polygon::close() {
    path.push_back(Vector2D(path[0]));
    closed = true;
    update();
}

void ASCII_Draw::Polygon::addPoint(const Vector2D & point) {
    path.push_back(Vector2D(point));
    int w = point.getX() - getPosition().getX(),
        h = point.getY() - getPosition().getY();
    // very very bad code
    if (w > getWidth())
    {
        resize((unsigned)w + 1, getHeight());
    }
    if(h > getHeight())
    {
        resize(getWidth(), (unsigned)h + 1);
    }
    update();
}

const std::vector<ASCII_Draw::Vector2D> &ASCII_Draw::Polygon::getPath() const {
    return path;
}

void ASCII_Draw::Polygon::setPath(const std::vector<ASCII_Draw::Vector2D> & path) {
    this->path = path;
    update();
}

bool ASCII_Draw::Polygon::isClosed() {
    return closed;
}
