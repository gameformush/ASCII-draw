//
// Created by myst on 2/26/18.
//

#include "Group.h"
#include <tuple>

namespace ASCII_Draw
{

    Group::Group(unsigned int width, unsigned int height, Vector2D position):Base_component(width, height, position) {
        this->children = std::vector<ASCII_Draw::Base_component *>(0);
    }

    void Group::remove(ASCII_Draw::Base_component *) {

    }

    void Group::remove_all() {

    }

    void Group::delete_child(ASCII_Draw::Base_component *) {

    }

    void Group::delete_all() {

    }

    void Group::_render() {
        for(auto child : children)
        {
            if (child->is_dirt())
            {
                this->update();
                child->render();
            }
        }
        if (this->is_dirt())
        {
            clear_buffer();
            this->compose();
        }
    }

    //Simplest compose implementation should change
    // inorder to use transformations
    void Group::compose() {
        for(auto child : children)
        {
            Vector2D pos = child->getPosition();
            int w = child->getWidth();
            int h = child->getHeight();
            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h; ++y) {

                    int xn = 0, yn = 0;
                    std::pair<int, int> new_coord = child->transfrom_point({x, y});
                    std::tie(xn, yn) = new_coord;
                    xn += pos.getX();
                    yn += pos.getY();
                    Pixel pixel = child->getPixel({x, y});
                    if (xn < 0 || yn < 0
                        ||xn >= getWidth() || yn >= getHeight())
                    {
                        continue; // skip all that doesn't fit into group buffer;
                    }
                    if(pixel.getContent() == getDefault_pixel().getContent() || pixel.isTransparent()) continue;

                    setPixel(
                             {xn , yn},
                             pixel
                     );
                }
            }
        }
    }

    void Group::add(Base_component *child) {
        child->setParent(this);
        children.push_back(child);
    }
}