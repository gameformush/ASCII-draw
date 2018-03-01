//
// Created by myst on 2/26/18.
//

#include "Base_component.h"
#include "./utility/Layer2D.h"

namespace ASCII_Draw
{

    Base_component::Base_component(int height, int width, Vector2D &position):position(position)
    {
        //make sure nothing is breaking because of zero width/height
        this->width = width != 0 ? width : 1;
        this->height = height != 0 ? height : 1;
        this->default_pixel = new Pixel(" ", 17, 255);
        this->buffer = std::vector<std::vector<ASCII_Draw::Pixel >>(
                (unsigned int)width, std::vector<Pixel >((unsigned int)height, Pixel(*this->default_pixel))
        );
        dirty = true;
    }   

    void Base_component::_render() {

    }

    void Base_component::render(bool force) {
        if(dirty || force){
            _render();
        }
        dirty = false;
    }

    void Base_component::resize(unsigned int w, unsigned int h) {
        this->width = w;
        this->height = h;
        buffer.resize(w);
        for(int i = 0; i < buffer.size(); i++)
        {
            buffer[i].resize(h, Pixel("+", 17, 255));
        }
    }

    bool Base_component::is_dirt() const {
        return dirty;
    }

    void Base_component::update() {
        if(parent != nullptr)
        {
            parent->update();
        }
        this->dirty = true;
    }

    // set for whole buffer value of default pixel
    void Base_component::clear_buffer() {
        for (int x = 0; x < this->getWidth(); x++) {
            for (int y = 0; y < this->getHeight(); y++) {
                this->setPixel({x, y}, getDefault_pixel());
            }
        }
    }

    // getters & setters
    void Base_component::setParent(Base_component *parent) {
        this->parent = parent;
    }

    void Base_component::setDefault_pixel(const Pixel &default_pixel) {
        this->default_pixel = new Pixel(default_pixel);
    }

    void Base_component::setHeight(int height) {
        this->height = height;
    }

    void Base_component::setWidth(int width) {
        this->width = width;
    }

    void Base_component::setPosition(const Vector2D &position) {
        this->position = position;
    }

    void Base_component::setPixel(const std::pair<int, int> & index, ASCII_Draw::Pixel pixel) {
        buffer[index.first][index.second] = Pixel(pixel);
    }

    const Pixel &Base_component::getDefault_pixel() const {
        return *default_pixel;
    }

    Base_component *Base_component::getParent() const {
        return parent;
    }

    int Base_component::getHeight() const {
        return height;
    }

    int Base_component::getWidth() const {
        return width;
    }

    const std::vector<std::vector<Pixel>> &Base_component::getBuffer() const {
        return buffer;
    }

    const Vector2D &Base_component::getPosition() const {
        return position;
    }

    ASCII_Draw::Pixel Base_component::getPixel(const std::pair<int, int> & index) const {
        return buffer[index.first][index.second];
    }

    // Transformation wrappers, look same but see no other way to do that

    void Base_component::scale(double factor) {
        if(parent != nullptr) parent->update();
        Transformable::scale(factor);
    }

    void Base_component::rotate(double rad) {
        if(parent != nullptr) parent->update();
        Transformable::rotate(rad);
    }

    void Base_component::translate(ASCII_Draw::Vector2D & v) {
        if(parent != nullptr) parent->update();
        Transformable::translate(v);
    }

    void Base_component::transform(ASCII_Draw::Transform_matrix & tm) {
        if(parent != nullptr) parent->update();
        Transformable::transform(tm);
    }

    void Base_component::set_transformation(ASCII_Draw::Transform_matrix & tm) {
        if(parent != nullptr) parent->update();
        Transformable::set_transformation(tm);
    }

    void Base_component::skew(double ax, double ay) {
        if(parent != nullptr) parent->update();
        Transformable::skew(ax, ay);
    }
}