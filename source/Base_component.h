//
// Created by myst on 2/26/18.
//
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <sstream>

#include "Pixel.h"
#include "Style.h"
#include "Transformable.h"
#include "utility/Vector2D.h"
#include "utility/Transform_matrix.h"

#ifndef ASCII_DRAW_BASE_COMPONENT_H
#define ASCII_DRAW_BASE_COMPONENT_H

namespace ASCII_Draw
{
    typedef std::vector<std::vector<Pixel>> Pixel_buffer;
    class Base_component:public Transformable
    {
    private:
        ASCII_Draw::Base_component * parent; // actually it's always be a Group class member
        ASCII_Draw::Pixel * default_pixel;
        ASCII_Draw::Vector2D position;
        Pixel_buffer buffer;
        int height;
        int width;
        bool dirty;

    protected:
        virtual void _render();
    public:
        Base_component(int width, int height, Vector2D &position);

        // Logic methods

        void resize(unsigned int, unsigned int);
        bool is_dirt() const;
        void update();
        void clear_buffer();
        void render(bool force=false);

        // setters

        void setPosition(const Vector2D &position);
        void setParent(Base_component *parent);
        void setDefault_pixel(const Pixel &default_pixel);
        void setHeight(int height);
        void setWidth(int width);
        void setPixel(const std::pair<int, int> &,ASCII_Draw::Pixel);

        // getters
        
        int getHeight() const;
        int getWidth() const;
        ASCII_Draw::Pixel   getPixel(const std::pair<int, int> &) const;
        Base_component *getParent() const;
        const Vector2D &getPosition() const;
        const Pixel_buffer &getBuffer() const;
        const Pixel &getDefault_pixel() const;

        /*
         * Transformation wrappers
         * Transformation itself don't involve re-rendering but require parent to update
         * in order to make re-composition
         */

        void scale(double factor = 1);
        void rotate(double rad = 0);
        void translate(ASCII_Draw::Vector2D &);
        void transform(ASCII_Draw::Transform_matrix &);
        void set_transformation(ASCII_Draw::Transform_matrix &);
        void skew(double ax =0, double ay = 0);
    };
}
#endif //ASCII_DRAW_BASE_COMPONENT_H
