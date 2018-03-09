//
// Created by myst on 2/26/18.
//

#include "Base_component.h"

namespace ASCII_Draw
{
    Base_component::Base_component():position(Vector2D({0, 0})), z_index(0) {
        this->width = 1;
        this->height = 1;
        this->default_pixel = Transparent;
        this->style = Pixel("*", RGB(34, 55, 34));
        this->parent = nullptr;
        this->buffer = std::vector<std::vector<ASCII_Draw::Pixel >>(
                (unsigned int)this->height, std::vector<Pixel >((unsigned int)this->width, Pixel(this->default_pixel))
        );
        dirty = true;
    }

    Base_component::Base_component(int width, int height, const Vector2D &position): position(position), z_index(0)
    {
        //make sure nothing is breaking because of zero width/height
        this->width = width >= 0 ? width : 1;
        this->height = height >= 0 ? height : 1;
        this->default_pixel = Transparent;
        this->style = Pixel("*", RGB(32, 32, 154));
        this->parent = nullptr;
        this->buffer = std::vector<std::vector<ASCII_Draw::Pixel >>(
                (unsigned int)this->height, std::vector<Pixel >((unsigned int)this->width, Pixel(this->default_pixel))
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

    void Base_component::resize(int w, int h) {
        if(w <= 0 || h <= 0){
            throw ERANGE;
        }
        this->width = w;
        this->height = h;
        buffer.resize((unsigned)h);
        for(int i = 0; i < buffer.size(); i++)
        {
            buffer[i].resize((unsigned)w, Pixel(getDefault_pixel()));
        }
        update();
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
        this->default_pixel = Pixel(default_pixel);
        update();
    }

    void Base_component::setHeight(int height) {
        resize(width, height);
    }

    void Base_component::setWidth(int width) {
        resize(width, height);
    }

    void Base_component::setPosition(const Vector2D &position) {
        this->position = position;
        update();
    }

    void Base_component::setPixel(const std::pair<int, int> &index, const Pixel &pixel) {
        buffer[index.second][index.first] = Pixel(pixel);
        update();
    }

    // getters
    const Pixel &Base_component::getDefault_pixel() const {
        return default_pixel;
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
        if(index.second >= height || index.first >= width ||
           index.second < 0 || index.first < 0){
            throw ERANGE;
        }
        return buffer[index.second][index.first];
    }

    // Transformation wrappers, look same but see no other way to do that

    void Base_component::scale(const std::pair<double, double> &factor) {
        if(parent != nullptr) parent->update();
        Transformable::scale(factor);
    }

    void Base_component::rotate(double rad) {
        if(parent != nullptr) parent->update();
        Transformable::rotate(rad);
    }

    void Base_component::translate(const Vector2D &v) {
        if(parent != nullptr) parent->update();
        Transformable::translate(v);
    }

    void Base_component::transform(const Transform_matrix &tm) {
        if(parent != nullptr) parent->update();
        Transformable::transform(tm);
    }

    void Base_component::set_transformation(const Transform_matrix &tm) {
        if(parent != nullptr) parent->update();
        Transformable::set_transformation(tm);
    }

    void Base_component::skew(double ax, double ay) {
        if(parent != nullptr) parent->update();
        Transformable::skew(ax, ay);
    }

    void Base_component::setStyle(const Pixel & pixel) {
        style = pixel;
        update();
    }

    const Pixel &Base_component::getStyle() const {
        return style;
    }

    void Base_component::setPixel(const std::pair<int, int> & pos) {
        setPixel(pos, style);
    }

    void Base_component::setBuffer(const Pixel_buffer & buffer) {
        this->buffer = buffer;
        update();
    }

    void Base_component::setZ_index(int index) {
        z_index = index;
    }

    int Base_component::getZ_index() const {
        return z_index;
    }
}