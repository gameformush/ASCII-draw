//
// Created by myst on 3/5/18.
//

#include "Rectangle.h"

void ASCII_Draw::Rectangle::_render() {
    helper.addPoint(getPosition());
    helper.addPoint(Vector2D(getPosition().getX() + getWidth(), getHeight()));
    helper.addPoint(Vector2D(getW, getPosition().getY() + getHeight()));
    helper.close();
    helper.render(true);
    setBuffer(helper.getBuffer());
}

ASCII_Draw::Rectangle::Rectangle() {}

ASCII_Draw::Rectangle::Rectangle(int width, int height, const ASCII_Draw::Vector2D & position) : Base_component(width + 1,
                                                                                                              height + 1,
                                                                                                              position) {
    helper = Polygon(width, height, position);
    helper.addPoint(position);
    helper.addPoint(Vector2D(position.getX() + width, position.getY()));
    helper.addPoint(Vector2D(position.getX() + width, position.getY() + height));
    helper.addPoint(Vector2D(position.getX(), position.getY() + height ));
    helper.close();
}
